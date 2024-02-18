package gui;

import javax.swing.*;
import java.awt.event.ActionEvent;
public class PlayAction extends ClientAction {
    private SubmitAction submitAction;

    public PlayAction(Client client, JTextArea textArea, SubmitAction submitAction) {
        super(client, "Play", textArea);
        this.submitAction = submitAction;
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        String file = submitAction.getFilename();
        String response = client.send("PLAY "+file);
        textArea.append("Request of Play: " + response + "\n");
    }
}