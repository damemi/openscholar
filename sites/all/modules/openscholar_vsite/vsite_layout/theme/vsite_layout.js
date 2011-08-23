Drupal.behaviors.scholarlayout = function() {
  Drupal.CTools.AJAX.commands.updateLayoutForm = function(data) {
	  scholarlayout_update_moved_elements(data.warning);
  }
	
  var layoutRegions = [ "#scholarlayout-header-left", "#scholarlayout-header-main", "#scholarlayout-header-right", "#scholarlayout-navbar", "#scholarlayout-left", "#scholarlayout-right", "#scholarlayout-footer" ];
  
  if($("#edit-page-type").val() == "none" || $("#edit-page-type").val() == "front"){
    layoutRegions.push("#scholarlayout-content-top");
    layoutRegions.push("#scholarlayout-content-bottom");
  }

  scholarlayout_add_sortable(layoutRegions);

  if (!scholarlayout_change_bound) {
    scholarlayout_change_bound = true;

    $('#cp-settings-form').submit(function() {
      scholarlayout_update_moved_elements(false);
      return true;
    });

    $("#edit-page-type").bind('change', function(e) {
      if (scholarlayout_catchchanges()) {
        $('#edit-secret-hidden-ahah').val($("#edit-page-type").val());
        $('#edit-secret-hidden-ahah').trigger('go_ahah');
        $("#edit-page-type").trigger('go_ahah');
        $("#scholarforms_save_warning").remove();
        scholarlayout_add_sortable(layoutRegions);
      } else {
        // revert
        $('#edit-page-type').val($("#edit-secret-hidden-ahah").val());
      }
    });
  }
  scholarlayout_add_removal_hooks();
  vsite_layout_setExceptionScroller();
  vsite_layout_add_category_select();
};

function scholarlayout_add_removal_hooks() {
  $(".ui-sortable .close-this:not(.close-this-processed)").addClass('close-this-processed')
  .click(function(e) {
    var parent = $(this).parent("dd");
    $("body").append("<div class='poof'></div>");

    // set the x and y offset of the poof animation <div> from cursor
    // position (in pixels)
    var xOffset = 24;
    var yOffset = 24;

    $('.poof').css({
      left : e.pageX - xOffset + 'px',
      top : e.pageY - yOffset + 'px'
    }).show(); // display the poof <div>
    animatePoof(); // run the sprite animation

    parent.appendTo("#scholarlayout-top-widgets");
    scholarlayout_update_moved_elements(true);
    vsite_layout_init_categories();

    parent.fadeIn('fast');
  });
}

var scholarlayout_change_bound = false;

function scholarlayout_afterdrag(event, ui) {
  
  var item = $(this);
  if(item.attr("id") == "scholarlayout-top-widgets" && ui.item && ui.item.children('a.add').length){
	  ui.item.clone(true).prependTo("#scholarlayout-top-widgets");
	  ui.item.children('a.add').click(); //auto-click the configure button
	  $(document).bind('CToolsDetachBehaviors',function(element) {
		  //Remove the box if it hasn't been replaced with an instance
		  ui.item.remove();
	  });
	  
	  vsite_layout_init_categories();
	  return;
  }//This started from the top
  
  scholarlayout_update_moved_elements(true);
};

/**
 * Update the form with the correct values after elemens have been moved.
 * @param warning
 * @return
 */
function scholarlayout_update_moved_elements(warning){
	  var regions = $("#scholarlayout-container > .scholarlayout-widgets-list");
	  $.each(regions, function(i, region) {
	    var items = $("#" + region.id + " > .scholarlayout-item");
	    var ids = "";
	    $.each(items, function(i, value) {
	      if (ids.length) {
	        ids += "|";
	      }
	      ids += value.id;
	    });
	    $('#edit-' + region.id).val(ids);
	  });

	  if (!$("#scholarforms_save_warning").length && warning) {
	    $("#cp-settings-layout").before(
	        $('<div id="scholarforms_save_warning" class="warning"><span class="warning tabledrag-changed">*</span> Your changes have not yet been saved. Click "Save Settings" for your changes to take effect</div>')
	    );
	  }
}

function scholarlayout_catchchanges() {
  if (!$("#scholarforms_save_warning").length 
      || confirm("Your changes have not been saved. Continue and lose your changes?")) {
    return true;
  }    
  return false;
};

function scholarlayout_add_sortable(layoutRegions) {
  var allRegions = layoutRegions.slice();
  allRegions[allRegions.length] = "#scholarlayout-top-widgets";
  $.each(allRegions, function(i, value) {
    $(value).sortable({
      connectWith : allRegions,
      stop : scholarlayout_afterdrag,
      tolerance : 'pointer',
      over : function(event, ui) {$(event.target).addClass('active');},
      out : function(event, ui) {$(event.target).removeClass('active');}
    });
  });
}

// The jQuery Poof Effect was developed by Kreg Wallace at The Kombine Group,
// Inc. http://www.kombine.net/

function animatePoof() {
  var bgTop = 0; // initial background-position for the poof sprit is '0 0'
  var frames = 5; // number of frames in the sprite animation
  var frameSize = 32; // size of poof <div> in pixels (32 x 32 px in this example)
  var frameRate = 80; // set length of time each frame in the animation will
                      // display (in milliseconds)

  // loop through amination frames
  // and display each frame by resetting the background-position of the poof
  // <div>
  for (i = 1; i < frames; i++) {
    $('.poof').animate({backgroundPosition : '0 ' + (bgTop - frameSize) + 'px'}, frameRate);
    bgTop -= frameSize; // update bgPosition to reflect the new
                        // background-position of our poof <div>
  }

  // wait until the animation completes and then hide the poof <div>
  setTimeout("$('.poof').remove()", frames * frameRate);
}

 // Horizontal Sliding Exceptions
function vsite_layout_setExceptionScroller() {

  $('span.toggle-exceptions').click(function() {
    $(this).siblings('div.layout-exceptions').stop().animate({
      right : '-20px'
    }, {
      queue : false,
      duration : 300
    });
  });

  $('div.layout-exceptions').click(function() {
    $(this).stop().animate({
      right : '-101%'
    }, {
      queue : false,
      duration : 300
    });
  });

}

//attaches event listeners to category select widget
//when its changed, show only widgets that match the category
function vsite_layout_add_category_select() {
 $('#widget-categories li').click(function() {
   $('#widget-categories li').removeClass('active');
   $(this).addClass('active');
   vsite_layout_init_categories();
   return false;
 });
 
 $('#widget-categories li:first').addClass('active');
 vsite_layout_init_categories();
}

function vsite_layout_init_categories(){
	var cat = $('#widget-categories li.active a').attr('href').substring(1);
	$('#scholarlayout-top-widgets').children('dd:not(.' + cat + ')').hide();
	$('#scholarlayout-top-widgets').children("."+cat + ':not(.disabled)').show();
}