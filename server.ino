#include <WiFi.h>
#include <WebServer.h>

// Replace with your network credentials
const char* ssid = "your_SSID";
const char* password = "your_PASSWORD"; 

// Create an instance of the WebServer on port 80
WebServer server(80);

void setup() {
  Serial.begin(115200);
  
  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }
  
  Serial.println();
  Serial.print("Connected to WiFi with IP: ");
  Serial.println(WiFi.localIP());
  
  // Define routes for the web server
  server.on("/", HTTP_GET, []() {
    server.send(200, "text/html", "<h1>ESP32 Web Server</h1><p>Hello from ESP32!</p>");
  });

  // Start the server
  server.begin();
}

void loop() {
  // Handle client requests
  server.handleClient();
}
