/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

(function($) {
  $().ready(function(){
    $('div a[alt="lookup"]').each(function(){
      $(this).click(function(){
        alert('lookup');
      });
    });
  });
})(jQuery);

