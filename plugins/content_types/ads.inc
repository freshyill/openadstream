<?php
// $Id: ads.inc,v 1.1.2.3 2009/12/30 03:41:46 damienmckenna Exp $
/**
 * @file
 * C-Tools integration for Open AdStream.
 */

/**
 * Implements hook_ctools_content_types().
 */
function openadstream_ads_ctools_content_types() {
  return array(
    'title' => t('Open AdStream Ads'),
  );
}

/**
 * Return all content types available.
 */
function openadstream_ads_content_type_content_types($plugin) {
  $types = array();

  $ads = _openadstream_positions();

  foreach($ads as $ad) {
    $types[$ad['name']] = _openadstream_ads_content_type_content_type($ad);
  }

  return $types;
}

function openadstream_ads_content_type_content_type($subtype, $plugin) {
  return _openadstream_ads_content_type_content_type($subtype);
}

/**
 * 
 */
function _openadstream_ads_content_type_content_type($ad) {
  return array(
    'title' => $ad['name'],
    'description' => $ad['description'],
    'category' => 'Open AdStream Ads',    
  );
}

/**
 * Implements hook_ctools_content_type_render().
 */
function openadstream_ads_content_type_render($subtype, $conf, $panel_args, $contexts) {
  $block = new StdClass;
  $block->content = _openadstream_block_js($subtype);
  $block->title = '';
  $block->delta = $subtype;
  $block->css_class = 'oas-ad oas-' . strtolower($subtype);
  return $block;
}

/**
 * Implements hook_ctools_content_type_admin_title().
 */
function openadstream_ads_content_type_admin_title($subtype, $conf, $contexts) {
  return 'Open AdStream Ads: ' . $subtype;
}

/**
 * Implements hook_ctools_content_type_admin_info().
 */
function openadstream_ads_content_type_admin_info($subtype, $conf, $contexts) {
  $block = new StdClass;
  $block->title = $subtype;
  $block->content = l('Settings may be modified', 'admin/settings/openadstream') . ', if needed';
  return $block;
}
