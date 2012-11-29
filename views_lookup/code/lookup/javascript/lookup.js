/* ===========================================================
* lookup.js
* ===========================================================
* Copyright 2012 Jordan and Huan
*
* ========================================================== */

(function($) {
  var id_prefix = '#';
	var lookup = {};
//below used by custom javascript
	lookup.setUp = function(inputId,viewId,eventHandler){
    var inputSelector = id_prefix + inputId;
    $(inputId).attr("ref", viewId);

    var lookupLink = lookup.findBrowseLink(inputId);
    var frameId = lookup.drawBrowseFrame();

    $(lookupLink).click(function(){
      lookup.showBrowse(frameId, viewId);
    });

    $(inputId).bind('selectback', eventHandler);
		/* 1. Add the custom attr to store viewId for the inputId input element
		 * 2. Find the browse link to bind click event
		 * 3. The select back action would trigger selectback event to fill back the
		 * return data to custom UI elements.
		 * eventHandler take the args array for the selected row data
		 */
	};

//below used by lookup module javascript
	lookup.getViewId = function(inputId){
		//TODO:get the viewId from input element
	};

	lookup.drawBrowseFrame = function(){
		//TODO:create the div element using jquery and return the id
		//the frame structure(include the ajax waiting img):
		//<div id="browse_frame"><div id="content_wrapper"><img/></div></div>
		//For image file, we use Drupal.settings.basePath plus img path to retrieve it
	};

	lookup.showBrowse = function(frameId,viewId){
		//TODO:call the jquery dialog to show the browse
		//consider how to create the ajax waiting UI before the ajax request return

		lookup.getViewContent(viewId);

		var frameSeletor = '#' + frameId;
		$(frameSeletor).dialog({
            autoOpen: false,
            height: 800,
            width: 600,
            modal: true,
            close: function() {
            	$(frameSeletor).remove();
            }
        });
	};

	lookup.getViewContent = function(viewId){
		//TODO:ajax request to get the view content
	};

	lookup.addSelectLink = function(){
		//TODO:add link for the first column for user selection data
		//trigger the selectback event in the click event of link
	};

  lookup.findBrowseLink = function(inputId) {
    return $('#' + inputId).parent('div').children('span').children('a');
  }

})(jQuery);
