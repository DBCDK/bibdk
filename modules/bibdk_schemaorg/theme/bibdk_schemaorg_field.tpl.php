<?php
/**
 * @file
 * template for openformat fields
 *
 * Available variables:
 *  $element: Render element
 */

if ($element['#typeof']) {
  echo '<span class="openformat-field" property="' . $element['#property'] . '" vocab="http://schema.org/" typeof="' . $element['#typeof'] . '">';
  echo '<span property="' . $element['#typeof_property'] . '">';
}
else {
  echo '<span class="openformat-field" property="' . $element['#property'] . '">';
};

echo drupal_render($element['#openformat_header']);
echo drupal_render($element['#openformat_field']);

if ($element['#typeof']) {
  echo "</span>\n</span>";
}
else {
  echo "</span>";
};


