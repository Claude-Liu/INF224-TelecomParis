package swing;

import javax.swing.AbstractAction;
import javax.swing.JTextArea;
import javax.swing.JTextField;
import java.awt.event.ActionEvent;

public class SubmitAction extends AbstractAction {
    private JTextField textField;
    private String filename;
    private JTextArea textArea;

    public SubmitAction(JTextField textField, JTextArea textArea) {
        super("submit");
        this.textField = textField;
        this.textArea = textArea;
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        filename = textField.getText();
        System.out.println("the filename is " + filename);
        textArea.append("The current file waiting for operation is " + filename + "\n");
    }

    public String getFilename() {
        return filename;
    }
}