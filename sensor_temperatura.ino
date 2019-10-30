int val;
float temp;

void temperatura(float t){ //metodo que verifica a temperatura e acende o respetivo led

   if(t < 20){            //temperatura correspondente a ligar o led conectado na porta 8
    digitalWrite(8,HIGH); 
    digitalWrite(9,LOW);
    digitalWrite(10,LOW);
    }
   else if(t<28){        //temperatura correspondente a ligar o led conectado na porta 9
    digitalWrite(8,LOW);
    digitalWrite(9,HIGH);
    digitalWrite(10,LOW);
    }
   else{                //temperatura correspondente a ligar o led conectado na porta 10
    digitalWrite(8,LOW);
    digitalWrite(9,LOW);
    digitalWrite(10,HIGH);
    }
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); //velocidade da transmissao dos dados do arduino para o pc (baudrate)
  pinMode(8,OUTPUT); //led azul ligado na porta 8
  pinMode(9,OUTPUT); //led verde ligado na porta 9
  pinMode(10,OUTPUT); //led vermelho ligado na porta 10
}

void loop() {
  val=analogRead(A0); // valor recebido entre 0-1023 

  Serial.println(val);
  temp = ((val*0.004887586)- 0.5)*100; //passar para ºC
  Serial.println(temp);
  
  temperatura(temp); 
  
  delay(1000); //espera 1sec antes de voltar a repetir
}
