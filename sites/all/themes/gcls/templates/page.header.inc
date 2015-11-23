<?php
/**
 * @file
 * Returns the HTML for the footer region.
 *
 * Complete documentation for this file is available online.
 * @see https://drupal.org/node/1728140
 */
?>
<header id="header" class="<?php print $classes; ?>">

  <?php print render($page['header']); ?>

  <div >
  	<a href="#"><img class="logo" alt="GCLS logo" src="sites/all/themes/gcls/images/Logo2016.png"></a>
  </div>

  <!-- <div class="catlinks">
    <a  href="https://encore.greenvillelibrary.org/iii/encore/myaccount"><button class="myaccount">My Account</button></a>
    <a  href="https://encore.greenvillelibrary.org"><button class="catsearch">Catalog</button></a>
  </div> -->

  <div class="socialmedia">
  	<p>
  		<a href="http://libanswers.greenvillelibrary.org/">Ask Us</a> 
      <a href="http://www.greenvillelibrary.org/index.php/about/locations-hours">Locations/Hours</a>
      <a href="http://www.greenvillelibrary.org/index.php/about/contact-us"> Contact Us</a>
      <a href="#"> About Us</a>
  	</p>
  <div class="icons">
		<a href="http://www.facebook.com/greenvillelibrary" target="_blank"><img alt="Facebook" src="sites/all/themes/gcls/images/face.png"></a>
		<a href="http://twitter.com/GCLSLibrary" target="_blank"><img alt="Twitter" src="sites/all/themes/gcls/images/twit.png"></a>
		<a href="http://www.youtube.com/user/GreenvilleLibrary" target="_blank"><img alt="YouTube" src="sites/all/themes/gcls/images/yout.png"></a>
		<a href="http://pinterest.com/gcls/" target="_blank"><img alt="Pinterest" src="sites/all/themes/gcls/images/pin.png"></a>
		<a href="http://instagram.com/greenvillelibrary" target="_blank"><img alt="Instagram" src="sites/all/themes/gcls/images/insta.png"></a>
	</div>

	<div class="nlink">
		<a href="http://eepurl.com/pYSXf" target="_blank"><button class="newsbutton">Get our newsletter</button></a>
	</div>
  </div>

      <?php if ($secondary_menu): ?>
      <nav class="header__secondary-menu" id="secondary-menu" role="navigation">
        <?php print theme('links__system_secondary_menu', array(
          'links' => $secondary_menu,
          'attributes' => array(
            'class' => array('links', 'inline', 'clearfix'),
          ),
          'heading' => array(
            'text' => $secondary_menu_heading,
            'level' => 'h2',
            'class' => array('element-invisible'),
          ),
        )); ?>
      </nav>
    <?php endif; ?>
    </header>