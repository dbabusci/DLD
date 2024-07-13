# DLD

## About
DLD is a simple wrapper ove the sudo apt install command which will install the most recently downloaded .deb package

## Options
No options -> installs the most recently downloaded debian package
"-a" -> installs all debian packages in the current directory
"-d" -> displays the most recently downloaded debian package
"-l" -> lists all of the downloaded debian packages in the current directory
"-h" -> lists all of the options and an explaination on what eahc option does

## Setup
1. Clone the repo
2. Run command 'make dld'
3. Run command 'sudo mv dld /usr/local/bin/'
4. Go to root directory and run command 'dld -h' to verify it is working
