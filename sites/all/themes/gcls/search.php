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

<!-- <form action="?" onsubmit="return searchEncore()"> -->
    
  <!-- REQUIRED with id="encoreSearchInput" -->
    <!-- <input id="encoreSearchInput" type="text"/> -->

    <!-- REQUIRED INPUT with id="encoreBase": <ENCORE_FQDN> fully qualified domain name such as "encore.mylibrary.com" -->
    <!-- <input type="hidden" id="encoreBase" value="http://encore.greenvillelibrary.org/iii/encore/search/" /> -->

    <!-- OPTIONAL search location hidden field to limit to a predefined scope -->
    <!-- <input type="hidden" id="encoreSearchLocation" value="__Lf:facetcollections:<Scope_#>:<Scope_#>:<Scope Label>::" /> -->
  
  <!-- OPTIONAL non-english language setting: <Language_Code> is code such as "spi" for spanish -->
  <!-- <input type="hidden" id="encoreLanguage" value="<Language_Code>" /> -->
    

    <!-- <input type="submit" value="SUBMIT" /> -->
<!-- </form>  -->
