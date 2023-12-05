let mSerial;

let connectButton;

let readyToReceive;

let data = JSON.parse(data).data;
let v2 = data.v2;
let v3 = data.v3;
let v4 = data.v4;


function receiveSerial() {
  let line = mSerial.readUntil("\n");
  trim(line);
  if (!line) return;


  }
 // serial update
  readyToReceive = true;

function connectToSerial() {
  if (!mSerial.opened()) {
    mSerial.open(9600);

    readyToReceive = true;
    connectButton.hide();
  }
}

function setup() {
  // setup project
  createCanvas(windowWidth, windowHeight);

  // setup serial
  readyToReceive = false;

  mSerial = createSerial();

  connectButton = createButton("Connect To Serial");
  connectButton.position(width / 2, height / 2);
  connectButton.mousePressed(connectToSerial);
}

function draw() {
  // project logic
  background(0);
  
  if (mSerial.opened() && readyToReceive) {
    readyToReceive = false;
    mSerial.clear();
    mSerial.write(0xab);
  }

}