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

  <script type="text/javascript">
   function searchEncore(){
        var encoreBaseURLInput,encoreBaseURL, searchInput, scopeInput, searchString, scopeString, locationHref, charRegExString, base64Regex;
       /*base64_encoding_map includes special characters that need to be
        encoded using base64 - these chars are "=","/", "\", "?"
        character : base64 encoded */
        var base64_encoding_map = {"=":"PQ==", "/": "Lw==", "\\":"XA==", "?":"Pw=="};

        var escapeRegExp = function(string) {
            return string.replace(/([.*+?^=!:${}()|\[\]\/\\])/g, "\\$1");
        }
       encoreBaseURLInput = document.getElementById("encoreBase");
       searchInput = document.getElementById("encoreSearchInput");

        if (searchInput && encoreBaseURLInput) {
            encoreBaseURL = encoreBaseURLInput.value;
            searchString = searchInput.value;
            for(var specialChar in base64_encoding_map) {
                charRegExString = escapeRegExp(specialChar);
                base64Regex = new RegExp(charRegExString, "g");
                searchString = searchString.replace(base64Regex, base64_encoding_map[specialChar])
            }
            searchString = encodeURIComponent(searchString);

            scopeInput = document.getElementById('encoreSearchLocation');

            if (scopeInput) {
                scopeString = scopeInput.value;
            }

            if (scopeString) {
                scopeString = encodeURIComponent(scopeString);
                locationHref = encoreBaseURL + "C__S" + searchString + scopeString +  "__Orightresult__U";
            } else {
                locationHref = encoreBaseURL + "C__S" + searchString + "__Orightresult__U";
            }
      
      languageSetting = document.getElementById("encoreLanguage");
      
      if (languageSetting) {
        locationHref = locationHref + "?lang=" + languageSetting.value;
      }
      
            window.location.href = locationHref;
        }
        return false;
    }
</script>

<form action="?" onsubmit="return searchEncore()">
    
  <!-- REQUIRED with id="encoreSearchInput" -->
    <input id="encoreSearchInput" type="text"/>

    <!-- REQUIRED INPUT with id="encoreBase": <ENCORE_FQDN> fully qualified domain name such as "encore.mylibrary.com" -->
    <input type="hidden" id="encoreBase" value="http://encore.greenvillelibrary.org/iii/encore/search/" />

    <!-- OPTIONAL search location hidden field to limit to a predefined scope -->
    <!-- <input type="hidden" id="encoreSearchLocation" value="__Lf:facetcollections:<Scope_#>:<Scope_#>:<Scope Label>::" /> -->
  
  <!-- OPTIONAL non-english language setting: <Language_Code> is code such as "spi" for spanish -->
  <!-- <input type="hidden" id="encoreLanguage" value="<Language_Code>" /> -->
    

    <input type="submit" value="SUBMIT" />
</form> 

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