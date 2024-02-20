import processing.serial.*;

Serial myPort;  // Objeto Serial para comunicación con Arduino
int diametroCirculo = 90;
int anchoFlecha = 100;
int altoFlecha = 60;

void setup() {
  size(600, 500);
  textAlign(CENTER, CENTER);
  
  // Inicia la comunicación con Arduino
  String portName = Serial.list()[0]; // Utiliza el primer puerto en la lista
  myPort = new Serial(this, portName, 9600);
}

void draw() {
  background(255);
  
  // Botón Retroceder (flecha izquierda azul)
  fill(0, 0, 255);
  rect(width / 2 + 40, height / 2 - altoFlecha / 2, anchoFlecha, altoFlecha);
  fill(255);
  text("Retroceder", width / 2 + 40 + anchoFlecha / 2, height / 2);
  
  // Botón Avanzar (flecha derecha azul)
  fill(0, 0, 255);
  rect(width / 2 + 180, height / 2 - altoFlecha / 2, anchoFlecha, altoFlecha);
  fill(255);
  text("Avanzar", width / 2 + 180 + anchoFlecha / 2, height / 2);
  
  // Botón Automático (círculo verde)
  float xCirculo = width / 4;  // Ajuste en esta línea
  float yCirculo = height / 2;
  
  // Verificar colisión del ratón con el círculo
  if (dist(mouseX, mouseY, xCirculo, yCirculo) > diametroCirculo / 2) {
    fill(0, 200, 0);
  } else {
    fill(0, 150, 0); // Cambia el color si hay colisión
  }
  
  ellipse(xCirculo, yCirculo, diametroCirculo, diametroCirculo);
  fill(0);
  text("Automático", xCirculo, yCirculo);
}

void mousePressed() {
  // Verificar si se hace clic en los botones
  if (mouseX > width / 2 + 40 && mouseX < width / 2 + 40 + anchoFlecha &&
      mouseY > height / 2 - altoFlecha / 2 && mouseY < height / 2 + altoFlecha / 2) {
    // Botón Retroceder presionado
    myPort.write('2');  // Envía '2' por el puerto serial
  } else if (mouseX > width / 2 + 180 && mouseX < width / 2 + 180 + anchoFlecha &&
             mouseY > height / 2 - altoFlecha / 2 && mouseY < height / 2 + altoFlecha / 2) {
    // Botón Avanzar presionado
    myPort.write('1');  // Envía '1' por el puerto serial
  } else if (dist(mouseX, mouseY, width / 4, height / 2) < diametroCirculo / 2) {
    // Botón Automático presionado
    myPort.write('0');  // Envía '0' por el puerto serial
  }
}
