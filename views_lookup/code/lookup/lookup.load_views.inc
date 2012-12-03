<?php

/*
 * Call views API to load the views content
 */
function lookup_load_views() {

  $result = '';

  if(!empty($_REQUEST['viewId']))
  {
    $view_id = $_REQUEST['viewId'];
    $result = views_embed_view($view_id);
  }

  print $result;

}
