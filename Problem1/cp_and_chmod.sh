#!/bin/bash

echo "Copying readswitch.cgi file to /usr/lib/cgi-bin."
sudo cp readswitch.cgi /usr/lib/cgi-bin
echo "Issuing permissions to readswitch.cgi"
sudo chmod +s /usr/lib/cgi-bin/readswitch.cgi
