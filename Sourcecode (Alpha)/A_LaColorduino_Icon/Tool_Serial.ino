void InitSerial(){
  Serial.begin(9600);
}
//----------------------------------------------------------------------------
void SerialInput() {
  if ( Serial.available() ) {
    //SubscriberCount = Serial.parseInt();
    ParseSerial();
    IncomingComplete = true;
    while ( Serial.read() == '\n' ){
      }
  }
  
  return;
}
//----------------------------------------------------------------------------
void ParseSerial() {
  // https://www.arduino.cc/reference/en/language/variables/data-types/string/functions/toint/
  // https://arduino.stackexchange.com/questions/1013/how-do-i-split-an-incoming-string
  // http://www.c-howto.de/tutorial/strings-zeichenketten/typumwandlung/

  // https://stackoverflow.com/questions/11068450/arduino-c-language-parsing-string-with-delimiter-input-through-serial-interfa

  //SubscriberCount = Serial.parseInt();
  //Environment.Temperatur = Serial.parseInt();
  //Environment.Temperatur = Serial.parseFloat();
  //Environment.Temperatur = (Serial.readStringUntil(';')).toFloat();
  //Environment.Temperatur = ( (float)Serial.parseInt() ) / 10;
  
  Device.Mode = Serial.parseInt();
  Device.Set  = Serial.parseInt();
  Serial.readStringUntil(';');

  switch (Device.Set) {
    case 0:
      break;
    
    case 5:
    // 5;5;0;0;1;  // Erste 0 für Animation | Zweite von 0-6 oder 7
      Device.WiFi_Skin             = Serial.parseInt();
      Device.WiFi_Code             = Serial.parseInt();
      Environment.SET_Ambientlight = Serial.parseInt();
      
      Symbolic_WiFi(Device.WiFi_Skin);
      break;
      
    case 9:
    // 9;9;1;12.5;1;1;
      Updating.Enable              = Serial.parseInt();
      Updating.Device              = Serial.parseFloat();
      Updating.State               = Serial.parseInt();
      Environment.SET_Ambientlight = Serial.parseInt();
      
      OTA_Update();
      break;
      
    case 10:
      Time.Hour                    = Serial.parseInt();
      Time.Minute                  = Serial.parseInt();
      Environment.SET_Ambientlight = Serial.parseInt();
      break;
    
    case 20:
    // 20;20;25.5;5;1;
      Environment.Temperatur       = Serial.parseFloat();
      Environment.Temp_Unit_2      = Serial.parseInt();
      Environment.SET_Ambientlight = Serial.parseInt();
      break;
      
    case 21:
      Environment.Pressure         = Serial.parseFloat();
      Environment.SET_Ambientlight = Serial.parseInt();
      break;
      
    case 30:
    // 30;30;50n;12.4;5;1;
      Weather.Icon                 = Serial.readStringUntil(';');
      Weather.Temperatur           = Serial.parseFloat();
      //Weather.Temp_Unit            = Serial.readStringUntil(';');
      Weather.Temp_Unit_2          = Serial.parseInt();
      Environment.SET_Ambientlight = Serial.parseInt();
      break;
      
    case 31:
      Weather.Pressure             = Serial.parseFloat();
      Environment.SET_Ambientlight = Serial.parseInt();
      break;
      
    case 32:
      Weather.Humidity             = Serial.parseFloat();
      Environment.SET_Ambientlight = Serial.parseInt();
      break;
      
    case 33: // 33;33;6.7;0;1;
      Weather.Wind_Speed           = Serial.parseFloat();
      Weather.Wind_Speed_Unit      = Serial.parseInt();
      Environment.SET_Ambientlight = Serial.parseInt();
      break;
      
    case 34:
      Weather.Forecast[0]          = Serial.readStringUntil(';');
      Weather.Forecast[1]          = Serial.readStringUntil(';');
      Weather.Forecast[2]          = Serial.readStringUntil(';');
      Weather.Forecast[3]          = Serial.readStringUntil(';');
      Weather.Forecast[4]          = Serial.readStringUntil(';');
      Environment.SET_Ambientlight = Serial.parseInt();
      break;
    
    case 35:
      Weather.SunriseHour          = Serial.parseInt();
      Weather.SunriseMinute        = Serial.parseInt();
      Environment.SET_Ambientlight = Serial.parseInt();
      break;
      
    case 36:
      Weather.SunsetHour           = Serial.parseInt();
      Weather.SunsetMinute         = Serial.parseInt();
      Environment.SET_Ambientlight = Serial.parseInt();
      break;
    
    case 40:
      YouTube.Subscriber           = Serial.parseInt();
      Environment.SET_Ambientlight = Serial.parseInt();
      break;
    
    case 41:
      YouTube.View                 = Serial.parseInt();
      Environment.SET_Ambientlight = Serial.parseInt();
      break;
    
    case 42:
      YouTube.Comment              = Serial.parseInt();
      Environment.SET_Ambientlight = Serial.parseInt();
      break;
    
    case 43:
      YouTube.Video                = Serial.parseInt();
      Environment.SET_Ambientlight = Serial.parseInt();
      break;
    
    case 50:
      Twitch.Follower              = Serial.parseInt();
      Environment.SET_Ambientlight = Serial.parseInt();
      break;

    case 51:
      Twitch.View                  = Serial.parseInt();
      Environment.SET_Ambientlight = Serial.parseInt();
      break;

    case 80:  // Twitter
      Twitter.Follower             = Serial.parseInt();
      Environment.SET_Ambientlight = Serial.parseInt();
      break;
    
    case 81:
      Twitter.Tweets               = Serial.parseInt();
      Environment.SET_Ambientlight = Serial.parseInt();
      break;
      
    case 82:  // 82;82;1;1;
      Twitter.Last_Retweet         = Serial.parseInt();
      Environment.SET_Ambientlight = Serial.parseInt();
      break;
      
   case 83:  // 83;83;1;1;
      Twitter.Last_Favorite        = Serial.parseInt();
      Environment.SET_Ambientlight = Serial.parseInt();
      break;
     
   case 90:  // 90;90;1;1;
      Facebook.Friends             = Serial.parseInt();
      Environment.SET_Ambientlight = Serial.parseInt();
      break; 
      
   case 100:
      Player.kills                 = Serial.parseInt();
      Player.assists               = Serial.parseInt();
      Player.deaths                = Serial.parseInt();
      Player.health                = Serial.parseInt();
      Player.flashed               = Serial.parseInt();
      Serial.readStringUntil(';');
      Round.bomb                   = Serial.readStringUntil(';');
      Round.win_team               = Serial.readStringUntil(';');
      CSGO.Delimiter               = Serial.parseInt();
      Environment.SET_Ambientlight = Serial.parseInt();
      break;

   case 110:  // 110;110;1;1;1;
      Power.Transmitting           = Serial.parseFloat();
      Power.Unit                   = Serial.parseInt();
      Environment.SET_Ambientlight = Serial.parseInt();
      break;
      
    default:
      break;
  }

  Serial.readStringUntil('\0');

  return;
}
//----------------------------------------------------------------------------
