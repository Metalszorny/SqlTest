package MsSqlTest;

import java.sql.Connection;
import java.sql.Date;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.Statement;
import java.util.ArrayList;
import javax.swing.table.DefaultTableModel;

/**
 * Interaction logic for JFrame2.
 */
public class JFrame2 extends javax.swing.JFrame
{
    //<editor-fold defaultstate="collapsed" desc="Fields">

    // The database connectionString.
    private String url = "jdbc:sqlserver://localhost:1433;databaseName=MsSqlTestDatabase";
    
    // The username of the database account.
    String username = "root";
    
    // The password of the database account.
    String password = "RootUser0123456789";

    // The Id value.
    private int id;

    // The Name value.
    private String name;

    // The Mothername value.
    private String mothername;

    // The Location value.
    private String location;

    // The Birthdate value.
    private Date birthdate;
    
    // </editor-fold>
    
    //<editor-fold defaultstate="collapsed" desc="Constructors">
    
    /**
     * Creates new form JFrame2.
     */
    public JFrame2()
    {
        initComponents();
    }
    
    // </editor-fold>
    
    //<editor-fold defaultstate="collapsed" desc="Methods">

    /**
     * This method is called from within the constructor to initialize the form.
     * WARNING: Do NOT modify this code. The content of this method is always
     * regenerated by the Form Editor.
     */
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        jButton5 = new javax.swing.JButton();
        jPanel1 = new javax.swing.JPanel();
        jButton2 = new javax.swing.JButton();
        jButton3 = new javax.swing.JButton();
        jButton4 = new javax.swing.JButton();
        jLabel1 = new javax.swing.JLabel();
        jTextField1 = new javax.swing.JTextField();
        jLabel2 = new javax.swing.JLabel();
        jTextField2 = new javax.swing.JTextField();
        jLabel3 = new javax.swing.JLabel();
        jTextField3 = new javax.swing.JTextField();
        jLabel4 = new javax.swing.JLabel();
        jTextField4 = new javax.swing.JTextField();
        jButton1 = new javax.swing.JButton();
        jScrollPane2 = new javax.swing.JScrollPane();
        jTable1 = new javax.swing.JTable();

        setDefaultCloseOperation(javax.swing.WindowConstants.DISPOSE_ON_CLOSE);
        setTitle("Pople");
        addWindowListener(new java.awt.event.WindowAdapter() {
            public void windowOpened(java.awt.event.WindowEvent evt) {
                formWindowOpened(evt);
            }
        });

        jButton5.setText("Close");
        jButton5.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jButton5ActionPerformed(evt);
            }
        });

        jButton2.setText("Add");
        jButton2.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jButton2ActionPerformed(evt);
            }
        });

        jButton3.setText("Edit");
        jButton3.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jButton3ActionPerformed(evt);
            }
        });

        jButton4.setText("Delete");
        jButton4.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jButton4ActionPerformed(evt);
            }
        });

        jLabel1.setText("Name:");

        jTextField1.addKeyListener(new java.awt.event.KeyAdapter() {
            public void keyReleased(java.awt.event.KeyEvent evt) {
                jTextField1KeyReleased(evt);
            }
        });

        jLabel2.setText("Mothername:");

        jTextField2.addKeyListener(new java.awt.event.KeyAdapter() {
            public void keyReleased(java.awt.event.KeyEvent evt) {
                jTextField2KeyReleased(evt);
            }
        });

        jLabel3.setText("Location:");

        jTextField3.addKeyListener(new java.awt.event.KeyAdapter() {
            public void keyReleased(java.awt.event.KeyEvent evt) {
                jTextField3KeyReleased(evt);
            }
        });

        jLabel4.setText("Birthdate:");

        jTextField4.addKeyListener(new java.awt.event.KeyAdapter() {
            public void keyReleased(java.awt.event.KeyEvent evt) {
                jTextField4KeyReleased(evt);
            }
        });

        javax.swing.GroupLayout jPanel1Layout = new javax.swing.GroupLayout(jPanel1);
        jPanel1.setLayout(jPanel1Layout);
        jPanel1Layout.setHorizontalGroup(
            jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanel1Layout.createSequentialGroup()
                .addContainerGap()
                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(jPanel1Layout.createSequentialGroup()
                        .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addComponent(jLabel2)
                            .addComponent(jLabel1))
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addComponent(jTextField1)
                            .addComponent(jTextField2)))
                    .addGroup(jPanel1Layout.createSequentialGroup()
                        .addComponent(jLabel4)
                        .addGap(18, 18, 18)
                        .addComponent(jTextField4))
                    .addGroup(jPanel1Layout.createSequentialGroup()
                        .addComponent(jButton2)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addComponent(jButton3)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addComponent(jButton4)
                        .addGap(0, 8, Short.MAX_VALUE))
                    .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, jPanel1Layout.createSequentialGroup()
                        .addComponent(jLabel3)
                        .addGap(24, 24, 24)
                        .addComponent(jTextField3)))
                .addContainerGap())
        );
        jPanel1Layout.setVerticalGroup(
            jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, jPanel1Layout.createSequentialGroup()
                .addContainerGap()
                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabel1)
                    .addComponent(jTextField1, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabel2)
                    .addComponent(jTextField2, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabel3)
                    .addComponent(jTextField3, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabel4)
                    .addComponent(jTextField4, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, 56, Short.MAX_VALUE)
                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jButton2)
                    .addComponent(jButton3)
                    .addComponent(jButton4))
                .addContainerGap())
        );

        jButton1.setText("List");
        jButton1.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jButton1ActionPerformed(evt);
            }
        });

        jTable1.setModel(new javax.swing.table.DefaultTableModel(
            new Object [][] {

            },
            new String [] {
                "Id", "Name", "Mothername", "Location", "Birthdate"
            }
        ) {
            boolean[] canEdit = new boolean [] {
                false, false, false, false, false
            };

            public boolean isCellEditable(int rowIndex, int columnIndex) {
                return canEdit [columnIndex];
            }
        });
        jTable1.setColumnSelectionAllowed(true);
        jTable1.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseClicked(java.awt.event.MouseEvent evt) {
                jTable1MouseClicked(evt);
            }
        });
        jScrollPane2.setViewportView(jTable1);
        jTable1.getColumnModel().getSelectionModel().setSelectionMode(javax.swing.ListSelectionModel.SINGLE_INTERVAL_SELECTION);

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addContainerGap()
                .addComponent(jScrollPane2, javax.swing.GroupLayout.DEFAULT_SIZE, 542, Short.MAX_VALUE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                    .addComponent(jPanel1, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addGroup(layout.createSequentialGroup()
                        .addComponent(jButton1)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                        .addComponent(jButton5)))
                .addGap(20, 20, 20))
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addContainerGap()
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addComponent(jScrollPane2, javax.swing.GroupLayout.DEFAULT_SIZE, 636, Short.MAX_VALUE)
                    .addGroup(layout.createSequentialGroup()
                        .addComponent(jPanel1, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                            .addComponent(jButton1)
                            .addComponent(jButton5))))
                .addContainerGap())
        );

        pack();
    }// </editor-fold>//GEN-END:initComponents

    /**
     * Handles the ActionPerformed event of the jButton5 control.
     * @param evt The ActionEvent instance containing the event data.
     */
    private void jButton5ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jButton5ActionPerformed
        // Close
        this.dispose();
    }//GEN-LAST:event_jButton5ActionPerformed

    /**
     * Handles the ActionPerformed event of the jButton2 control.
     * @param evt The ActionEvent instance containing the event data.
     */
    private void jButton2ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jButton2ActionPerformed
        // Add
        try
        {
            // The fields must not be empty.
            if (name != null && mothername != null && location != null && birthdate != null && !name.isEmpty() && !mothername.isEmpty() && !location.isEmpty())
            {
                id = 0;
                boolean matchFound = false;

                // Open a connection to the database.
                Class.forName("com.microsoft.sqlserver.jdbc.SQLServerDriver");
                Connection conn = DriverManager.getConnection(url, username, password);

                // Get the items from the People table.
                Statement stmt = conn.createStatement();
                ResultSet rs = stmt.executeQuery("SELECT * FROM [MsSqlTestDatabase].[dbo].[People]");
                
                // Get the number of the existing items.
                while (rs.next())
                {
                    id++;
                    
                    if (!matchFound && 
                            rs.getString("Name") == name && 
                            rs.getString("Mothername") == mothername && 
                            rs.getString("Location") == location && 
                            rs.getDate("Birthdate") == birthdate &&  
                            rs.getBoolean("IsDeleted") == true)
                    {
                        matchFound = true;
                        id = rs.getInt("Id");
                        
                        break;
                    }
                }

                // Close the resultSet.
                rs.close();
                
                if (!matchFound)
                {
                    // Add new item to the People table.
                    PreparedStatement ps = conn.prepareStatement("INSERT INTO [MsSqlTestDatabase].[dbo].[People] (Id, Name, Mothername, Location, Birthdate, IsDeleted) VALUES (?, ?, ?, ?, ?, ?)");

                    // Set the values of the preparedStatement.
                    ps.setInt(1, id + 1);
                    ps.setString(2, name);
                    ps.setString(3, mothername);
                    ps.setString(4, location);
                    ps.setDate(5, birthdate);
                    ps.setBoolean(6, false);

                    // Execute.
                    ps.execute();

                    // Close the preparedStatement.
                    ps.close();
                }
                else
                {
                    // Edit the IsDeleted value to false.
                    PreparedStatement ps = conn.prepareStatement("UPDATE [MsSqlTestDatabase].[dbo].[People] SET IsDeleted = ? WHERE Id = ?");

                    // Set the values of the preparedStatement.
                    ps.setBoolean(1, false);
                    ps.setInt(2, id);

                    // Update the table.
                    ps.executeUpdate();

                    // Close the preparedStatement.
                    ps.close();
                }
                
                // Close the connection.
                conn.close();

                // Refresh.
                GetData();
            }
        }
        catch (Exception e)
        {

        }
    }//GEN-LAST:event_jButton2ActionPerformed

    /**
     * Handles the ActionPerformed event of the jButton3 control.
     * @param evt The ActionEvent instance containing the event data.
     */
    private void jButton3ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jButton3ActionPerformed
        // Edit
        try
        {
            // The fields must not be empty.
            if (name != null && mothername != null && location != null && birthdate != null && !name.isEmpty() && !mothername.isEmpty() && !location.isEmpty())
            {
                // An item must be selected in the jTable.
                if (jTable1.getSelectedRow() >= 0)
                {
                    // Get the Id value of the selected item.
                    id = Integer.parseInt(jTable1.getValueAt(jTable1.getSelectedRow(), 0).toString());

                    // Open a connection to the database.
                    Class.forName("com.microsoft.sqlserver.jdbc.SQLServerDriver");
                    Connection conn = DriverManager.getConnection(url, username, password);

                    // Edit the values.
                    PreparedStatement ps = conn.prepareStatement("UPDATE [MsSqlTestDatabase].[dbo].[People] SET Name = ?, Mothername = ?, Location = ?, Birthdate = ? WHERE Id = ?");

                    // Set the values of the preparedStatement.
                    ps.setString(1, name);
                    ps.setString(2, mothername);
                    ps.setString(3, location);
                    ps.setDate(4, birthdate);
                    ps.setInt(5, id);

                    // Update the table.
                    ps.executeUpdate();

                    // Close the preparedStatement and the connection.
                    ps.close();
                    conn.close();

                    // Refresh
                    GetData();
                }
            }
        }
        catch (Exception e)
        {

        }
    }//GEN-LAST:event_jButton3ActionPerformed

    /**
     * Handles the ActionPerformed event of the jButton4 control.
     * @param evt The ActionEvent instance containing the event data.
     */
    private void jButton4ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jButton4ActionPerformed
        // Delete
        try
        {
            // An item must be selected in the jTable.
            if (jTable1.getSelectedRow() >= 0)
            {
                /* Logical Delete */
                // Get the Id value of the selected item.
                id = Integer.parseInt(jTable1.getValueAt(jTable1.getSelectedRow(), 0).toString());

                // Open a connection to the database.
                Class.forName("com.microsoft.sqlserver.jdbc.SQLServerDriver");
                Connection conn = DriverManager.getConnection(url, username, password);

                // Edit the IsDeleted value to true.
                PreparedStatement ps = conn.prepareStatement("UPDATE [MsSqlTestDatabase].[dbo].[People] SET IsDeleted = ? WHERE Id = ?");

                // Set the values of the preparedStatement.
                ps.setBoolean(1, true);
                ps.setInt(2, id);

                // Update the table.
                ps.executeUpdate();

                // Close the preparedStatement and the connection.
                ps.close();
                conn.close();
                
                // Refresh
                GetData();
            }
        }
        catch (Exception e)
        {

        }
    }//GEN-LAST:event_jButton4ActionPerformed

    /**
     * Handles the ActionPerformed event of the jButton1 control.
     * @param evt The ActionEvent instance containing the event data.
     */
    private void jButton1ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jButton1ActionPerformed
        // List
        GetData();
    }//GEN-LAST:event_jButton1ActionPerformed

    /**
     * Handles the MouseClicked event of the jTable1 control.
     * @param evt The MouseEvent instance containing the event data.
     */
    private void jTable1MouseClicked(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_jTable1MouseClicked
        // An item must be selected in the jTable.
        if (jTable1.getSelectedRow() >= 0)
        {
            try
            {
                // Get the Id value of the selected item.
                int selectedRowIndex = jTable1.getSelectedRow();

                // Give the jTextField texts the selected values.
                jTextField1.setText(jTable1.getValueAt(selectedRowIndex, 1).toString());
                jTextField2.setText(jTable1.getValueAt(selectedRowIndex, 2).toString());
                jTextField3.setText(jTable1.getValueAt(selectedRowIndex, 3).toString());
                jTextField4.setText(jTable1.getValueAt(selectedRowIndex, 4).toString());
            }
            catch (Exception e)
            {
                // Empty the jTextField texts.
                jTextField1.setText("");
                jTextField2.setText("");
                jTextField3.setText("");
                jTextField4.setText("");
            }
        }
        else
        {
            // Empty the jTextField texts.
            jTextField1.setText("");
            jTextField2.setText("");
            jTextField3.setText("");
            jTextField4.setText("");
        }
    }//GEN-LAST:event_jTable1MouseClicked

    /**
     * Handles the WindowOpened event of the form control.
     * @param evt The WindowEvent instance containing the event data.
     */
    private void formWindowOpened(java.awt.event.WindowEvent evt) {//GEN-FIRST:event_formWindowOpened
        // Preset values.
        GetData();
    }//GEN-LAST:event_formWindowOpened

    /**
     * Handles the KeyReleased event of the jTextField1 control.
     * @param evt The WindowEvent instance containing the event data.
     */
    private void jTextField1KeyReleased(java.awt.event.KeyEvent evt) {//GEN-FIRST:event_jTextField1KeyReleased
        name = jTextField1.getText();
    }//GEN-LAST:event_jTextField1KeyReleased

    /**
     * Handles the KeyReleased event of the jTextField2 control.
     * @param evt The WindowEvent instance containing the event data.
     */
    private void jTextField2KeyReleased(java.awt.event.KeyEvent evt) {//GEN-FIRST:event_jTextField2KeyReleased
        mothername = jTextField2.getText();
    }//GEN-LAST:event_jTextField2KeyReleased

    /**
     * Handles the KeyReleased event of the jTextField3 control.
     * @param evt The WindowEvent instance containing the event data.
     */
    private void jTextField3KeyReleased(java.awt.event.KeyEvent evt) {//GEN-FIRST:event_jTextField3KeyReleased
        location = jTextField3.getText();
    }//GEN-LAST:event_jTextField3KeyReleased

    /**
     * Handles the KeyReleased event of the jTextField4 control.
     * @param evt The WindowEvent instance containing the event data.
     */
    private void jTextField4KeyReleased(java.awt.event.KeyEvent evt) {//GEN-FIRST:event_jTextField4KeyReleased
        birthdate = Date.valueOf(jTextField4.getText());
    }//GEN-LAST:event_jTextField4KeyReleased

    /**
     * Gets the data.
     */
    private void GetData()
    {
        try
        {
            // Clear existing items.
            DefaultTableModel dm = (DefaultTableModel)jTable1.getModel();
            dm.getDataVector().removeAllElements();
            
            // Open a connection to the database.
            Class.forName("com.microsoft.sqlserver.jdbc.SQLServerDriver");
            Connection conn = DriverManager.getConnection(url, username, password);
            
            // Get the items from the People table.
            ArrayList<Person> people = new ArrayList<>();
            Statement stmt = conn.createStatement();
            ResultSet rs = stmt.executeQuery("SELECT * FROM [MsSqlTestDatabase].[dbo].[People] WHERE IsDeleted = 0");

            // Store the items in a Person list.
            while (rs.next())
            {
                Person person = new Person();
                
                person.setId(rs.getInt("Id"));
                person.setName(rs.getString("Name"));
                person.setMothername(rs.getString("Mothername"));
                person.setLocation(rs.getString("Location"));
                person.setBirthdate(rs.getDate("Birthdate"));
                person.setIsDeleted(rs.getBoolean("IsDeleted"));
                
                people.add(person);
            }
            
            // Close the resultSet, the statement and the connection.
            rs.close();
            stmt.close();
            conn.close();
            
            // Fill the jTable rows with the values of the People table.
            for (int i = 0; i < people.size(); i++)
            {
                DefaultTableModel model = (DefaultTableModel) jTable1.getModel();
                
                model.addRow(new Object[]
                {
                    people.get(i).getId(),
                    people.get(i).getName(),
                    people.get(i).getMothername(),
                    people.get(i).getLocation(),
                    people.get(i).getBirthdate()
                });
            }
        }
        catch (Exception e)
        {
            
        }
    }
    
    /**
     * The main method of the JFrame2.
     * @param args the command line arguments
     */
    public static void main(String args[])
    {
        /* Set the Nimbus look and feel */
        //<editor-fold defaultstate="collapsed" desc=" Look and feel setting code (optional) ">
        
        /* If Nimbus (introduced in Java SE 6) is not available, stay with the default look and feel.
         * For details see http://download.oracle.com/javase/tutorial/uiswing/lookandfeel/plaf.html 
         */
        try
        {
            for (javax.swing.UIManager.LookAndFeelInfo info : javax.swing.UIManager.getInstalledLookAndFeels())
            {
                if ("Nimbus".equals(info.getName()))
                {
                    javax.swing.UIManager.setLookAndFeel(info.getClassName());
                    break;
                }
            }
        }
        catch (ClassNotFoundException ex)
        {
            java.util.logging.Logger.getLogger(JFrame2.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        }
        catch (InstantiationException ex)
        {
            java.util.logging.Logger.getLogger(JFrame2.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        }
        catch (IllegalAccessException ex)
        {
            java.util.logging.Logger.getLogger(JFrame2.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        }
        catch (javax.swing.UnsupportedLookAndFeelException ex)
        {
            java.util.logging.Logger.getLogger(JFrame2.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        }
        
        //</editor-fold>

        /* Create and display the form */
        java.awt.EventQueue.invokeLater(new Runnable()
        {
            public void run()
            {
                new JFrame2().setVisible(true);
            }
        });
    }

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JButton jButton1;
    private javax.swing.JButton jButton2;
    private javax.swing.JButton jButton3;
    private javax.swing.JButton jButton4;
    private javax.swing.JButton jButton5;
    private javax.swing.JLabel jLabel1;
    private javax.swing.JLabel jLabel2;
    private javax.swing.JLabel jLabel3;
    private javax.swing.JLabel jLabel4;
    private javax.swing.JPanel jPanel1;
    private javax.swing.JScrollPane jScrollPane2;
    private javax.swing.JTable jTable1;
    private javax.swing.JTextField jTextField1;
    private javax.swing.JTextField jTextField2;
    private javax.swing.JTextField jTextField3;
    private javax.swing.JTextField jTextField4;
    // End of variables declaration//GEN-END:variables

    // </editor-fold>
}
