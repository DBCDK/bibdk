<?php

define('BIBDK_CAPTCHA_SILENCE', 1500);

/**
 * Generate a MP3 file by concatenating individual files
 *
 * @param String $letters  String of letters to build a file from
 * @param Boolean $case_sentitive
 * @return String  MP3 file data
 */
function bibdkcaptcha_generate_audio_mpeg($letters, $case_sentitive) {
  $silence = variable_get('bibdk_captcha_silence', BIBDK_CAPTCHA_SILENCE);
  $out_data = '';
  $lang = 'eng';

  global $language;
  if ($language->language == 'da') {
    $lang = 'dan';
  }
  $audio_path = drupal_get_path('module', 'bibdkcaptcha') . '/audio/' . $lang . '/';

  $letters = str_split($letters);
  if (!$case_sentitive && $lang == 'dan') {
    $letters = bibdkcaptcha_generate_case_sensitive($letters); //Upper-/lowercase is currently supported in dansih only
  }
  foreach ($letters as $letter) {
    $filename = $audio_path . strtoupper($letter) . '.mp3';
    $fp = fopen($filename, 'r');
    $data = fread($fp, filesize($filename)); // read file in
    fclose($fp);
    $raw_header = bibdkcaptcha_mpeg_header_raw($data);
    $header = bibdkcaptcha_mpeg_header_decode($raw_header);
    $quite = bibdkcaptcha_mpeg_create_silence($header, $silence);
    $data .= $quite;
    $data = bibdkcaptcha_scramble_audio_data_mpeg($data);
    $out_data .= $data;
  }
  return $out_data;
}

function bibdkcaptcha_scramble_audio_data_mpeg($data) {
  $start = 4; // 4 byte (32 bit) frame header

  $start += rand(1, 64); // randomize starting offset
  $datalen = strlen($data) - $start - 256; // leave last 256 bytes unchanged

  for ($i = $start; $i < $datalen; $i += 64) {
    $ch = ord($data{$i});
    if ($ch < 9 || $ch > 119) {
      continue;
    }

    $data{$i} = chr($ch + rand(-8, 8));
  }
  return $data;
}

/**
 * Generate a wav file by concatenating individual files
 *
 * @param array $letters  String of letters to build a file from
 * @param $case_sentitive Boolean
 * @return string  WAV file data
 */
function bibdkcaptcha_generate_audio_wav($letters, $case_sentitive) {
  $silence = variable_get('bibdk_captcha_silence', BIBDK_CAPTCHA_SILENCE);
  $out_data = '';
  $lang = 'eng';

  global $language;
  if ($language->language == 'da') {
    $lang = 'dan';
  }
  $audio_path = drupal_get_path('module', 'bibdkcaptcha') . '/audio/' . $lang . '/';

  $letters = str_split($letters);
  if (!$case_sentitive && $lang == 'dan') {
    $letters = bibdkcaptcha_generate_case_sensitive($letters); //Upper-/lowercase is currently supported in dansih only
  }

  $data_len = 0;
  foreach ($letters as $letter) {
    $filename = $audio_path . strtoupper($letter) . '.wav';
    $fp = fopen($filename, 'rb');
    $file = array();
    $data = fread($fp, filesize($filename)); // read file in
    fclose($fp);
    $wave = bibdkcaptcha_wave_riff($data);
    $wave['format'] = $wave['fmt']['AudioFormat'];
    $wave['channels'] = $wave['fmt']['NumChannels'];
    $wave['sample_rate'] = $wave['fmt']['SampleRate'];
    $wave['bits_per_sample'] = $wave['fmt']['BitsPerSample'];
    $padding = $wave['channels'] * $wave['sample_rate'] * $wave['bits_per_sample'] / 8 * $silence / 1000;
    $padding -= $padding % $wave['fmt']['BlockAlign'];
    $data_len += strlen($wave['data']['audio']) + $padding;
    $wave['data'] = $wave['data']['audio'] . str_pad('', $padding, "\x00");
    $files[] = $wave;
  }

  $out_data = '';
  for ($i = 0; $i < sizeof($files); ++$i) {
    if ($i == 0) { // output header
      $out_data .= pack('C4VC8', ord('R'), ord('I'), ord('F'), ord('F'), $data_len + 36, ord('W'), ord('A'), ord('V'), ord('E'), ord('f'), ord('m'), ord('t'), ord(' '));

      $out_data .= pack('VvvVVvv', 16, $files[$i]['format'], $files[$i]['channels'], $files[$i]['sample_rate'], $files[$i]['sample_rate'] * (($files[$i]['bits_per_sample'] * $files[$i]['channels']) / 8), ($files[$i]['bits_per_sample'] * $files[$i]['channels']) / 8, $files[$i]['bits_per_sample']);

      $out_data .= pack('C4', ord('d'), ord('a'), ord('t'), ord('a'));

      $out_data .= pack('V', $data_len);
    }

    $out_data .= $files[$i]['data'];
  }

  $out_data = bibdkcaptcha_scramble_audio_data($out_data);
  return $out_data;
}

/**
 * Randomly modify the audio data to scramble sound and prevent binary recognition.
 * Take care not to "break" the audio file by leaving the header data intact.
 *
 * @param $data String data in mp3 of wav format
 * @return String
 */
function bibdkcaptcha_scramble_audio_data($data) {
  $start = strpos($data, 'data') + 4; // look for "data" indicator
  if ($start === FALSE) {
    $start = 44;
  } // if not found assume 44 byte header

  $start += rand(1, 4); // randomize starting offset
  $datalen = strlen($data) - $start;
  $step = 1;

  for ($i = $start; $i < $datalen; $i += $step) {
    $ch = ord($data{$i});
    if ($ch == 0 || $ch == 255) {
      continue;
    }

    if ($ch < 16 || $ch > 239) {
      $ch += rand(-6, 6);
    }
    else {
      $ch += rand(-12, 12);
    }

    if ($ch < 0) {
      $ch = 0;
    }
    elseif ($ch > 255) {
      $ch = 255;
    }

    $data{$i} = chr($ch);

    $step = rand(1, 4);
  }

  return $data;
}

/**
 * Helper function to support case sensitivness in danish speaken audio captcha.
 *
 * @param array $letters
 * @return array $sens_letters with strings to support upper- and lowercase. Dansih only
 */
function bibdkcaptcha_generate_case_sensitive($letters) {
  $sens_letters = array();
  foreach ($letters as $letter) {
    if (!is_numeric($letter)) {
      if (ctype_upper($letter)) {
        $sens_letters[] = 'stort';
      }
      else {
        $sens_letters[] = 'lille';
      }
    }
    $sens_letters[] = $letter;
  }
  return $sens_letters;
}

/**
 * Reads the data subchunk from the beginning of a data string. Verification that
 * this is a data subchunk can be done by checking that SubChunkID is 0x64617461
 * (big-endian) spelling 'data'.
 *
 * @param array $data
 * @return array
 */
function bibdkcaptcha_wave_data($data) {
  $audio = unpack('NSubChunkID/VSubChunkSize', $data);
  $audio['size'] = $audio['SubChunkSize'] + 8;
  $audio['audio'] = substr($data, 8, $audio['SubChunkSize']);
  return $audio;
}

/**
 * Reads the fmt subchunk from the beginning of a data string. Verification that
 * this is a fmt subchunk can be done by checking that SubChunkID is 0x666d7420
 * (big-endian) spelling 'fmt ' (note the space!).
 *
 * @param array $data
 * @return array
 */
function bibdkcaptcha_wave_fmt($data) {
  $fmt = unpack('NSubChunkID/VSubChunkSize/vAudioFormat/vNumChannels/VSampleRate/VByteRate/vBlockAlign/vBitsPerSample', $data);
  $fmt['size'] = $fmt['SubChunkSize'] + 8;
  return $fmt;
}

/**
 * Reads the riff chunk from the beginning of a data string. Verification that
 * this is a riff chunk can be done by checking that ChunkID is 0x52494646
 * (big-endian) spelling 'RIFF'.
 *
 * @param array $data
 * @return array
 */
function bibdkcaptcha_wave_riff($data) {
  $riff = unpack('NChunckID/VChunkSize/NFormat', $data);
  $riff['size'] = $riff['ChunkSize'] + 8;
  $data = substr($data, 12);
  $riff['fmt'] = bibdkcaptcha_wave_fmt($data);
  $data = substr($data, $riff['fmt']['size']);
  $riff['data'] = bibdkcaptcha_wave_data($data);
  return $riff;
}


function bibdkcaptcha_mpeg_header_format() {
  // 32 bit MPEG header format described by lowest bit field first
  return array(
    'Emphasis' => 2,
    'Home' => 1,
    'Copy' => 1,
    'ModeExtension' => 2,
    'Mode' => 2,
    'PrivateBit' => 1,
    'Padding' => 1,
    'Frequency' => 2,
    'Bitrate' => 4,
    'CRC' => 1,
    'Layer' => 2,
    'Version' => 2,
    'Sync' => 11,
  );
}

/**
 * Extract header information from a data string.
 *
 * @param $data string of raw data
 * @return array containing header info in raw format
 */
function bibdkcaptcha_mpeg_header_raw($data) {
  $MPEG_HEADER_FORMAT = bibdkcaptcha_mpeg_header_format();
  $header = unpack('NHeader', $data);
  $offset = 0;
  $audio = array();

  foreach($MPEG_HEADER_FORMAT as $name => $bits) {
    $audio[$name] = ($header['Header'] >> $offset) & (1 << $bits) - 1;
    $offset += $bits;
  }

  return $audio;
}

/**
 * Bitrates for the different layers of mpeg audio.
 *
 * @return translation table for raw bitrate information.
 */
function bibdkcaptcha_mpeg_bitrate() {
  $bitrates_mpeg1 = array(
    // starting at 32 with steps of 32 ending at 448
    3 => array_merge(array('Free'), range(32, 448, 32), array('Reserved')),
    // starting at 32, 1 step 16, 2 steps 8, 4 steps 16, 4 steps 32, and 2 step 64
    2 => array('Free', 32, 48, 56, 64, 80, 96, 112, 128, 160, 192, 224, 256, 320, 384, 'Reserved'),
    // starting 32, 4 steps 8, 4 steps 16, 4 steps 32, 2 steps 64
    1 => array_merge(array('Free'), range(32, 64, 8), range(80, 128, 16), range(160, 256, 32), array(320, 'Reserved')),
    0 => array(),
  );

  $mpeg2_layer_2_3 = array_merge(array('Free'), range(8, 64, 8), range(80, 160, 16), array('Reserved'));
  $bitrates_mpeg2 = array(
    3 => array_merge(array('Free', 32, 48, 56), range(64, 192, 16), array(224, 256, 'Reserved')),
    2 => $mpeg2_layer_2_3,
    1 => $mpeg2_layer_2_3,
    0 => array(),
  );

  $bitrates = array(
    0 => $bitrates_mpeg2,
    1 => array(),
    2 => $bitrates_mpeg2,
    3 => $bitrates_mpeg1,
  );

  return $bitrates;
}

/**
 * Version of mpeg.
 *
 * @return translation table of raw mpeg version.
 */
function bibdkcaptcha_mpeg_version() {
  return array(
    0 => 2.5,
    1 => 'Reserved',
    2 => 2,
    3 => 1,
  );
}

/**
 * Layer of mpeg.
 *
 * @return translation table of raw mpeg layer.
 */
function bibdkcaptcha_mpeg_layer() {
  return array(
    0 => 'Reserved',
    1 => 3,
    2 => 2,
    3 => 1,
  );
}

/**
 * Sampling frequency of mpeg for the different layers.
 *
 * @return translation table of raw mpeg frequencies.
 */
function bibdkcaptcha_mpeg_frequency() {
  return array(
    0 => array(11025, 12000, 8000, 'Reserved',),
    1 => array(),
    2 => array(22050, 24000, 16000, 'Reserved',),
    3 => array(44100, 48000, 32000, 'Reserved',),
  );
}

/**
 * Mono, stereo, or dual channel.
 */
function bibdkcaptcha_mpeg_mode() {
  return array(
    0 => 'Stereo',
    1 => 'Joint Stereo',
    2 => 'Dual channel',
    3 => 'Mono'
  );
}

function bibdkcaptcha_mpeg_mode_extension() {
  return array(
    0 => '',
    1 => 'Intensify stereo',
    2 => 'MS stereo',
    3 => 'Intensify stereo, MS stereo',
  );
}

function bibdkcaptcha_mpeg_emphasis() {
  return array(
    0 => 'None',
    1 => '50/15ms',
    2 => 'Reserved',
    3 => 'CCITT J.17',
  );
}

function bibdkcaptcha_mpeg_header_decode($raw_header) {
  $MPEG_HEADER_METRICS = bibdkcaptcha_mpeg_metrics($raw_header['Version']);
  $MPEG_HEADER_METRICS['Bitrate'] = $MPEG_HEADER_METRICS['Bitrate'][$raw_header['Layer']];
  $header = array();

  foreach($MPEG_HEADER_METRICS as $field => $metrics) {
    $header[$field] = $metrics[$raw_header[$field]];
  }

  return $header;
}

/**
 * Samples for mpeg audio file depends on which layer is used.
 *
 * @param $layer integer of value 1, 2, or 3
 * @return sample count
 */
function bibdkcaptcha_mpeg_frame_size($layer) {
  if ($layer & 0x2) { // Test if layer is either 2 or 3
    return 1152;
  }
  else {
    return 384;
  }
}

/**
 * Length of physical frame for mpeg audio frame
 *
 * @param $header mpeg audio header
 * @return byte count
 */
function bibdkcaptcha_mpeg_frame_length($header) {
  if ($header['Layer'] & 0x2) { // Test if layer is either 2 or 3
    return floor(144 * $header['Bitrate'] * 1000 / ($header['Frequency']) + $header['Padding']);
  }
  else {
    return floor((12 * $header['Bitrate'] * 1000 / $header['Frequency'] + $header['Padding']) * 4);
  }
}

/**
 * Get metric for a specific version of mpeg audio.
 *
 * @param $version mpeg version
 * @return array of arrays
 */
function bibdkcaptcha_mpeg_metrics($version) {
  $MPEG_HEADER_METRICS = array(
    'Sync' => array(0x7ff => 'Sync'),
    'Version' => bibdkcaptcha_mpeg_version(),
    'Layer' => bibdkcaptcha_mpeg_layer(),
    'CRC' => array(0, 1),
    'Bitrate' => bibdkcaptcha_mpeg_bitrate(),
    'Frequency' => bibdkcaptcha_mpeg_frequency(),
    'Padding' => array(0, 1),
    'PrivateBit' => array(0, 1),
    'Mode' => bibdkcaptcha_mpeg_mode(),
    'ModeExtension' => bibdkcaptcha_mpeg_mode_extension(),
    'Copy' => array(0, 1),
    'Home' => array(0, 1),
    'Emphasis' => bibdkcaptcha_mpeg_emphasis(),
  );

  $MPEG_HEADER_METRICS['Bitrate'] = $MPEG_HEADER_METRICS['Bitrate'][$version];
  $MPEG_HEADER_METRICS['Frequency'] = $MPEG_HEADER_METRICS['Frequency'][$version];
  return $MPEG_HEADER_METRICS;
}

/**
 * Encode mpeg audio header to bit format
 *
 * @param $header mpeg audio header as an associative array
 * @return 32 bit integer (4 bytes)
 */
function bibdkcaptcha_mpeg_header_encode($header) {
  $MPEG_HEADER_FORMAT = bibdkcaptcha_mpeg_header_format();
  $raw_header = 0;
  $offset = 0;
  $version_encoded = array_search($header['Version'], bibdkcaptcha_mpeg_version());
  $layer_encoded = array_search($header['Layer'], bibdkcaptcha_mpeg_layer());
  $MPEG_HEADER_METRICS = bibdkcaptcha_mpeg_metrics($version_encoded);
  $MPEG_HEADER_METRICS['Bitrate'] = $MPEG_HEADER_METRICS['Bitrate'][$layer_encoded];

  foreach($MPEG_HEADER_FORMAT as $field => $bits) {
    $raw_value = array_search($header[$field], $MPEG_HEADER_METRICS[$field]);
    $raw_header |= $raw_value << $offset;
    $offset += $bits;
  }

  return $raw_header;
}

/**
 * Create a mpeg audio clip containing of a specified length.
 *
 * @param $header mpeg header as an associative array including Sync field
 * @param $milliseconds specifies how long the silence should be
 * @return string
 */
function bibdkcaptcha_mpeg_create_silence($header, $milliseconds) {
  $raw_header = bibdkcaptcha_mpeg_header_encode($header);
  $frame_size = bibdkcaptcha_mpeg_frame_size($header['Layer']);
  $frame_count = floor($milliseconds * $header['Frequency'] / $frame_size / 1000);
  $frame_length = bibdkcaptcha_mpeg_frame_length($header);
  $frame = pack('N', $raw_header) . str_pad('', $frame_length - 4, "\x00");
  return str_pad('', $frame_length * $frame_count, $frame);
}
