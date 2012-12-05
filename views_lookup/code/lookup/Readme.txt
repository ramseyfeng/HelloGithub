This module is a tiny user interface kind of module for user input via a popup lookup browse. This module depends on 
D7 views module. The display data format on browse lookup is table format of views.

How to use this module for your module development? It's very easy, just two things you need to do. 
First, when you create your form textfield element via form API, please specify the attribute #lookup to TRUE.
Example:
  $form['city'] = array(
    '#lookup' => TRUE,
    '#type' => 'textfield',
    '#title' => t('City'),
    '#size' => 12,
    '#default_value' => isset($form_state['values']['city']) ? $form_state['values']['city']
          : NULL,
  );

Second, invoke Lookup.setUp javascript function in your javascript. This function includes three parameters:
First parameter : the id of the input which you want to add lookup for it.
Second parameter: the name of view you want to display on lookup browse.
Three parameter: the callback funtion used to bind with selectback event, there are two parameter for this callback
which are event object and selected array with the row data you selected from the browse. 
Example:
    Lookup.setUp('edit-city', 'city_list', function(event,selectedList){
    	$('#edit-city').val(selectedList[0]);
    	$('#edit-country').val(selectedList[2]);
    	$('#edit-continent').val(selectedList[4]);
    });

More detail about how to use you can take a look at the lookup test module for an example.