[![CMake](https://github.com/joedinsmoor/GSMDecoder/actions/workflows/cmake-single-platform.yml/badge.svg)](https://github.com/joedinsmoor/GSMDecoder/actions/workflows/cmake-single-platform.yml)

# GSMDecoder
Decode GSM 7-bit SMS messages



To install and run in Python:

`- pip install -r requirements.txt`

`- python3 menu.py`


The menu will output:
`Enter filename of binary to decode:`  

Once entered, decoder.py is called and will print any and all sms messages that it decodes to the terminal. (In the future, to separate files for each message)

To install and run in C++:

`- cmake .`

`- make `

`- ./GSMDecoder`

You will be prompted to enter a file to decode, any text messages, contacts, or call history will be saved to individual csv or txt files in the working directory
