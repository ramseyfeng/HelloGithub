<?php

/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

function lookup_load_views() {
  
    $result = array();
    
    $view_id = $_REQUEST['viewId'];
    $content = views_embed_view($view_id);
    
    print $content;
    
}
