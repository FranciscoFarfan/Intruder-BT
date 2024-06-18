/*
 * Universidad Politecnica de San Luis Potosi
 * Programacion III Java
 */
package serialcontroller;

/**
 *
 * @author Francisco Javier Farfan Vazque, 181779, 181779@upslp.edu.mx
 */
import com.fazecast.jSerialComm.SerialPort;

public class BluetoothSerialCommunication {

    public static void main(String[] args) {
        // Encuentra el puerto serial correspondiente
        SerialPort[] ports = SerialPort.getCommPorts();
        SerialPort port = null;
        for (SerialPort p : ports) {
            if (p.getSystemPortName().equals("COM5")) { // Cambia esto al puerto correcto
                port = p;
                break;
            }
        }

        if (port == null) {
            System.out.println("No se encontró el puerto especificado.");
            return;
        }

        // Configura el puerto serial
        port.setBaudRate(9600);
        port.setNumDataBits(8);
        port.setNumStopBits(SerialPort.ONE_STOP_BIT);
        port.setParity(SerialPort.NO_PARITY);

        // Abre el puerto
        if (port.openPort()) {
            System.out.println("Puerto abierto exitosamente.");
        } else {
            System.out.println("No se pudo abrir el puerto.");
            return;
        }

        // Envía datos al Arduino
        String message = "Hola Arduino!";
        byte[] messageBytes = message.getBytes();
        port.writeBytes(messageBytes, messageBytes.length);

        // Lee datos del Arduino
        byte[] buffer = new byte[1024];
        int bytesRead = port.readBytes(buffer, buffer.length);
        if (bytesRead > 0) {
            String receivedMessage = new String(buffer, 0, bytesRead);
            System.out.println("Mensaje recibido: " + receivedMessage);
        }

        // Cierra el puerto
        port.closePort();
        System.out.println("Puerto cerrado.");
    }
}
