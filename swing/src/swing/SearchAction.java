package swing;

import javax.swing.*;
import java.awt.event.ActionEvent;
public class SearchAction extends ClientAction {
    private SubmitAction submitAction;

    public SearchAction(Client client, JTextArea textArea, SubmitAction submitAction) {
        super(client, "search", textArea);
        this.submitAction = submitAction;
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        String file = submitAction.getFilename();
        String response = client.send("SEARCH " + file );
        textArea.append("Request of Search: " + response + "\n");
    }
}