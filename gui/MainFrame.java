package gui;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.io.IOException;

public class MainFrame extends JFrame {
    private static final long serialVersionUID = 1L;
    private JTextArea textArea;

    // Actions
    private Action playAction;
    private Action searchAction;
    private Action exitAction;
    private JTextField textField;
    private SubmitAction submitAction;
    // Client
    private Client client;

    public MainFrame() {
        super("Set-Top Box");
        
        // Configuration of the JFrame
        setLayout(new BorderLayout());
        if(System.getProperty("os.name").contains("Mac")) {
            System.setProperty("apple.laf.useScreenMenuBar", "true");
        }

        //connection to the server
        try {
            client = new Client("localhost", 3331);
        } catch (IOException e) {
            e.printStackTrace();
            JOptionPane.showMessageDialog(this, "cannot connect to the server", "connection error", JOptionPane.ERROR_MESSAGE);
        }

        // Configuration of JTextArea
        textArea = new JTextArea(30, 100);
        JScrollPane scrollPane = new JScrollPane(textArea);

        // create the panel and add the text field and the button
        textField = new JTextField(20); 
        submitAction = new SubmitAction(textField, textArea);
        JButton submitButton = new JButton(submitAction);
        JPanel panel = new JPanel();
        panel.add(textField);
        panel.add(submitButton);
        add(panel, BorderLayout.NORTH);


        // creation and configuration of the menu
        JMenuBar menuBar = new JMenuBar();
        JMenu menu = new JMenu("Options");
        add(scrollPane, BorderLayout.SOUTH);

        // actions
        createActions();

        // add actions to the menu
        menu.add(new JMenuItem(playAction));
        menu.add(new JMenuItem(searchAction));
        menu.add(new JMenuItem(exitAction));
        menuBar.add(menu);
        setJMenuBar(menuBar);


        // configuration of the JFrame
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        pack();
        setVisible(true);
    }

    private void createActions() {
        playAction = new PlayAction(client, textArea, submitAction);
        searchAction = new SearchAction(client, textArea, submitAction);
        exitAction = new AbstractAction("Quitter") {
            @Override
            public void actionPerformed(ActionEvent e) {
                System.exit(0);
            }
        };
    }
}
