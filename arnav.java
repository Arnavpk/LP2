import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class arnav extends JFrame implements ActionListener {

    // Text field for typing message
    JTextField messageField;

    // Text area for showing chat/messages
    JTextArea chatArea;

    // Send button
    JButton sendButton;

    public arnav() {
        setTitle("Hospital And Medical Expert System");
        setSize(400, 300);

        chatArea = new JTextArea();
        chatArea.setEditable(false);

        JScrollPane scrollPane = new JScrollPane(chatArea);
        add(scrollPane, BorderLayout.CENTER);

        JPanel bottomPanel = new JPanel();

        bottomPanel.setLayout(new BorderLayout());

        messageField = new JTextField();

        sendButton = new JButton("Send");

        sendButton.addActionListener(this);

        bottomPanel.add(messageField, BorderLayout.CENTER);

        bottomPanel.add(sendButton, BorderLayout.WEST);

        add(bottomPanel, BorderLayout.SOUTH);

        setVisible(true);
    }

    public void actionPerformed(ActionEvent e) {

        String message = messageField.getText();

        if (!message.isEmpty()) {

            chatArea.append("You: " + message + "\n");

            if (message.equalsIgnoreCase("Fever")) {
                chatArea.append("System: Take aspirin 500.\n");
            } else if (message.equalsIgnoreCase("Cold")) {
                chatArea.append("System: Drink Alcohol\n");
            } else if (message.equalsIgnoreCase("Pain")) {
                chatArea.append("System: Drink beer.\n");
            } else {
                chatArea.append("System: Problem not found.\n");
            }

            messageField.setText("");
        }
    }

    public static void main(String[] args) {
        new arnav();
    }
}