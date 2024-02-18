package gui;
import javax.swing.*;
import javax.swing.AbstractAction;
import java.awt.event.ActionEvent;

public abstract class ClientAction extends AbstractAction {
    protected Client client;
    protected JTextArea textArea; // Declare the textArea variable

    public ClientAction(Client client, String name, JTextArea textArea) {
        super(name);
        this.client = client;
        this.textArea = textArea;
    }

    @Override
    public abstract void actionPerformed(ActionEvent e);
}
