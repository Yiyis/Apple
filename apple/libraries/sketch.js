
var song;
var songs;
var song1;
var song2;
var song3;
var song4;
var song5;


var serial;                            // variable to hold an instance of the serialport library
var portName = '/dev/cu.usbmodem1421';// fill in your serial port name here
var inData;                            // for incoming serial data


function setup() {
  createCanvas(400, 300);
  serial = new p5.SerialPort();       // make a new instance of the serialport library
  //serial.on('list', printList);  // set a callback function for the serialport list event
  serial.on('connected', serverConnected); // callback for connecting to the server
  serial.on('open', portOpen);        // callback for the port opening
  serial.on('data', serialEvent);     // callback for when new data arrives
  serial.on('error', serialError);    // callback for errors
  serial.on('close', portClose);      // callback for the port closing
 
  serial.list();                      // list the serial ports
  serial.open(portName);              // open a serial port
  song1.setVolume(0.5);
  song2.setVolume(0.5);
  song3.setVolume(0.5);
  song4.setVolume(0.5);
 
}


function preload(){
  
   song1 = loadSound("FuckOff.mp3");
   song2 = loadSound("Heng.mp3");
   song3 = loadSound("Ah.mp3");
   song4 = loadSound("DonTouchMe.mp3");  

   //songs = [song1,song2,song3,song4,song5];  
   //song  = random(songs);
}

function serverConnected() {
  console.log('connected to server.');
}
 
function portOpen() {
  console.log('the serial port opened.')
}

function serverConnected() {
  console.log('connected to server.');
}
 
function portOpen() {
  console.log('the serial port opened.')
}
 
 
function serialError(err) {
  console.log('Something went wrong with the serial port. ' + err);
}
 
function portClose() {
  console.log('The serial port closed.');
}

function serialEvent() {
  inData = Number(serial.read());
}


function draw(){
background(0);
  fill(255);
  text("sensor value: " + inData, 30, 30);
  console.log(inData);
     if (inData == 5){
      song1.play();
 }
      if (inData == 3){
      song2.play();
 }
      if (inData == 1){
      song3.play();
 }
      if (inData == 6){
      song4.play();
 }






}