/* ===========================================================
* lookup.js
* ===========================================================
* Copyright 2012 Jordan and Huan
*
* ========================================================== */

(function($) {

  //Define global Lookup object.
  Lookup = {};

  /**
   * Setup method for Lookup object.
   *   Add click event for Lookup icon.
   *   Generate the frame for views to display.
   *   Show the Lookup views embeded in the frame.
   *   Bind the selectback event with the custom eventHandler
   *   (If user has not bind any callback method,
   *   the first element's value will be filled into the corresponding input element.)
   *   @inputId the id of input element with a lookup.
   *   @viewId the id of the view which you want to associate it with the input element.\
   *   @eventHandler callback method for user to do post handling
   */
  Lookup.setUp = function(inputId,viewId,eventHandler){
    var lookupLink = Lookup.findBrowseLink(inputId);
    $(lookupLink).click(function(){
      var frameId = Lookup.drawBrowseFrame();
      Lookup.showBrowse(frameId, viewId,inputId);
    });

    $('#' + inputId).bind('selectback', eventHandler);
  };

  /**
   * Method to draw a frame for the views to display.
   */
  Lookup.drawBrowseFrame = function(){
    var frame = '<div id="lookup_frame" title="Lookup Browse">' +
                  '<div id="lookup_content_wrapper">' +
                    '<div class="browse-loading"></div>' +
                  '</div>' +
                '</div>';
    $(frame).appendTo('body');
    return 'lookup_frame';
  };

  /**
   * Using jQuery UI to show the dialog for views.
   */
  Lookup.showBrowse = function(frameId,viewId,inputId){

    Lookup.getViewContent(viewId,inputId,frameId);

    var frameSeletor = '#' + frameId;
    $(frameSeletor).dialog({
      height: 400,
      width: 500,
      modal: true,
      close: function() {
        $(frameSeletor).remove();
      }
    });
  };

  /**
   * Using ajax to load the specified views content.
   */
  Lookup.getViewContent = function(viewId,inputId,frameId){
    //TODO:ajax request to get the view content
    $.ajax({
      type: "GET",
      url: "?q=lookup/get/views",
      data: {
        "viewId": viewId
      },
      dataType: "html",
      success: function(htmlData){
        //replace the content of lookup_content_wrapper with htmldata
        $('#lookup_content_wrapper').html(htmlData);

        Lookup.addSelectLink(inputId,frameId);
      }
    });
  };

  /**
   * Add link for every first td elements, and bind click event for every links
   */
  Lookup.addSelectLink = function(inputId,frameId){
    $('#lookup_content_wrapper .view-content table tbody tr td:first-child').each(function(){
      var inputSelector = '#' + inputId;
      var value = $(this).text();
      $(this).text('');
      var link = '<a href="#">' + value + '</a>';
      $(this).html(link);

      //Add click event to the link of first column
      $(this).children('a').click(function(){
        Lookup.handleSelect.call(this, inputSelector);
        $('#' + frameId).dialog("close");
      });
    });
  };

  /**
   * Handling select event
   */
  Lookup.handleSelect = function(inputSelector) {
    var list = new Array();
    $(this).parent().parent().children().each(function(index){
      list[index]= $.trim($(this).text());
    });
    if(typeof $(inputSelector).data('events').selectback == 'undefined') {
      //Default assign the first column value into the input element
      $(inputSelector).val(list[0]);
    } else {
      //Call user defined callback method with whole row's values passing as Array'
      $(inputSelector).trigger('selectback', [list]);
    }
  }

  /**
   * Find lookup link element by specified input element's id
   */
  Lookup.findBrowseLink = function(inputId) {
    return $('#' + inputId).parent('div').children('span').children('a');
  }

})(jQuery);

