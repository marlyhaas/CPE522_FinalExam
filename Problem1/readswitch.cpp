#include <iostream>         // for the input/output
#include <stdlib.h>         // for the getenv call
#include <sys/sysinfo.h>    // for the system uptime call
#include <cgicc/Cgicc.h>    // the cgicc headers
#include <cgicc/CgiDefs.h>
#include <cgicc/HTTPHTMLHeader.h>
#include <cgicc/HTMLClasses.h>
#define SW_GPIO "/sys/class/gpio/gpio60/"
using namespace std;
using namespace cgicc;

void writeGPIO(string filename, string value){
   fstream fs;
   string path(SW_GPIO);
   fs.open((path + filename).c_str(), fstream::out);
   fs << value;
   fs.close();
}

string readSwitch(){
   ifstream fs;
   string path(SW_GPIO);
   fs.open((path + "/value").c_str());
   string value, line;
   while(getline(fs, line)) value = line;
   if (value == "1"){
       value = "On";
   }
   else if (value == "0"){
       value = "Off";
   }
   fs.close();
   return value;
}

int main(){
   Cgicc form;                             // the CGI form object
   string switchVal;                       // switch value
   writeGPIO("direction", "in");
   // get the state of the form that was submitted - script calls itself
   bool isStatus = form.queryCheckbox("status");
   char *value = getenv("REMOTE_ADDR");    // The remote IP address
 
   // generate the form but use states that are set in the submitted form
   cout << HTTPHTMLHeader() << endl;       // Generate the HTML form
   cout << html() << head() << title("CPE522 Final Exam: Reading Digital Input") << head() << endl;
   cout << body() << h1("CPE522 Final Exam: Reading Digital Input") << endl; 
   cout << body() << ("Reading a GPIO Pin via a Web Browser\n") << endl;
   cout << "<form action=\"/cgi-bin/readswitch.cgi\" method=\"POST\">\n";
   cout << "<input type=\"submit\" value=\"Read Switch\" />";
   cout << "</div></form>";
 
   switchVal = readSwitch();                 // read switch state and output to form
   cout << "<div> The value of the switch is " << switchVal << "</div>";
   cout << body() << html();
   return 0;
}
