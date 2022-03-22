//Pin definitions
int R_Pin = 23;
int G_Pin = 22;
int B_Pin = 21;
int W_Pin = 19;

// Setting PWM frequency, channels and bit resolution
const int freq = 26000;
const int redChannel = 0;
const int greenChannel = 1;
const int blueChannel = 2;
const int whiteChannel = 3;
// Bit resolution 2^8 = 256
const int resolution = 8;


void SetPins(int R, int G, int B, int W)
{
  R_Pin = R;
  G_Pin = G;
  B_Pin = B;
  W_Pin = W;
}

void InitializeLED()
{
    // put your setup code here, to run once:
  // configure LED PWM functionalitites
  ledcSetup(redChannel, freq, resolution);
  ledcSetup(greenChannel, freq, resolution);
  ledcSetup(blueChannel, freq, resolution);
  ledcSetup(whiteChannel, freq, resolution);
  
  // attach the channel to the GPIO to be controlled
  ledcAttachPin(R_Pin, redChannel);
  ledcAttachPin(G_Pin, greenChannel);
  ledcAttachPin(B_Pin, blueChannel);
  ledcAttachPin(W_Pin, whiteChannel);
}

void WriteLED(int R,int G,int B,int W)
{
  ledcWrite(redChannel, R);
  ledcWrite(greenChannel, G);
  ledcWrite(blueChannel, B);
  ledcWrite(whiteChannel, W);
}

void WriteLED(int Values[4])
{
  ledcWrite(redChannel, Values[1]);
  ledcWrite(greenChannel, Values[2]);
  ledcWrite(blueChannel, Values[3]);
  ledcWrite(whiteChannel, Values[4]);
}