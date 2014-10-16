# BIBDK CCL - CQL CONVERTER
This module converts ccl strings to cql. If the need exists, this module can be
extended to convert cql to ccl.

# How to
Call the function bibdk_yaz_convert_ccl_to_cql($ccl). This will return an array
that contains the key 'cql' if request went well, or the key 'error' if not

# Requirements
This module requires the php extension php-yaz (> 1.1.7)
