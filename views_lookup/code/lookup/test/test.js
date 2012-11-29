/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

(function($) {
  $().ready(function(){
    lookup.setUp('edit-city', 'city_list', 'updateCityInfo');
    lookup.setUp('edit-country', 'city_list', 'updateCityInfo');
    lookup.setUp('edit-continent', 'city_list', 'updateCityInfo');

    updateCityInfo = function(params) {

    }

  });
})(jQuery);

