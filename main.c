#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

int postrequest(void)
{
CURL *curl;
  CURLcode res;
  char url[256] = "https://delta-api.fourfusion.nl/test/";

  char *variable = malloc(256);
  strcpy(variable, "ASDFDJKDEEEAMFMEFMafkjasdfasflkjasdhf!@#$%*()--");
  puts(variable);

  //Add url_route to url
  strcat(url, variable);
  puts(url);

  // Free 'variable', so there won't be any memory leaks.
  free(variable);

  /* In windows, this will init the winsock stuff. THIS NEEDS TO BE UNCOMMENTED IF YOU TEST ON WINDOWS. */
  //curl_global_init(CURL_GLOBAL_ALL);

  /* get a curl handle */
  curl = curl_easy_init();
  if(curl) {
    /* First set the URL that is about to receive our POST. This URL can
       just as well be a https:// URL if that is what should receive the
       data. */
    curl_easy_setopt(curl, CURLOPT_URL, url);
    /* Now specify the POST data */
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, "temperature=42.0");

    /* Perform the request, res will get the return code */
    res = curl_easy_perform(curl);

    // This closes all the connections
    curl_easy_cleanup(curl);
  }
  curl_global_cleanup();
  return 0;
}

int main(void)
{
  int i = postrequest();
}