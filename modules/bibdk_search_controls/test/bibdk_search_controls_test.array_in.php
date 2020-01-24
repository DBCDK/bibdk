<?php

/**
 * Create controls variable for unit testing.
 * @return array $controls
 */
function _bibdk_search_controls_variable_create() {

    $controls = array
    (
        'select_name' => array
            (
                'title' => 'select_title',
                'type' => 'select',
                'label' => 'select_label',
                'name' => 'select_name',
                'description' => 'select_description',
                'access_key' => 's',
                'tab_index' => '10',
                'values' => array
                    (
                        '5' => array
                            (
                                'label' => 'select_option_label_0',
                                'value' => 'select_option_value_0',
                                'default' => '1',
                                'sort' => '-10',
                            ),
                        '3' => array
                            (
                                'label' => 'select_option_label_1',
                                'value' => 'select_option_value_1',
                                'default' => '0',
                                'sort' => '-9',
                            ),
                        '2' => array
                            (
                                'label' => 'select_option_label_2',
                                'value' => 'select_option_value_2',
                                'default' => '0',
                                'sort' => '-8',
                            ),
                    ),
            ),

        'radios_name' => array
            (
                'title' => 'radios_title',
                'type' => 'radios',
                'label' => 'radios_label',
                'name' => 'radios_name',
                'description' => 'radios_description',
                'access_key' => 'r',
                'tab_index' => '20',
                'values' => array
                    (
                        '5' => array
                            (
                                'label' => 'radios_option_label_0',
                                'value' => 'radios_option_value_0',
                                'default' => '1',
                                'sort' => '-10',
                            ),
                        '3' => array
                            (
                                'label' => 'radios_option_label_1',
                                'value' => 'radios_option_value_1',
                                'default' => '0',
                                'sort' => '-9',
                            ),
                        '2' => array
                            (
                                'label' => 'radios_option_label_2',
                                'value' => 'radios_option_value_2',
                                'default' => '0',
                                'sort' => '-8',
                            ),
                    ),
            ),

        'checkboxes_name' => array
            (
                'title' => 'checkboxes_title',
                'type' => 'checkboxes',
                'label' => 'checkboxes_label',
                'name' => 'checkboxes_name',
                'description' => 'checkboxes_description',
                'access_key' => 'c',
                'tab_index' => '30',
                'values' => array
                    (
                        '5' => array
                            (
                                'label' => 'checkboxes_option_label_0',
                                'value' => 'checkboxes_option_value_0',
                                'default' => '1',
                                'sort' => '-10',
                            ),
                        '3' => array
                            (
                                'label' => 'checkboxes_option_label_1',
                                'value' => 'checkboxes_option_value_1',
                                'default' => '0',
                                'sort' => '-9',
                            ),
                        '2' => array
                            (
                                'label' => 'checkboxes_option_label_2',
                                'value' => 'checkboxes_option_value_2',
                                'default' => '0',
                                'sort' => '-8',
                            ),
                    ),

            ),

    );

    return $controls;

}