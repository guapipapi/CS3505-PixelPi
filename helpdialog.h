/**
 * @author Carlos Alatorre
 *
 * The help page that is shown at the beginning of the screen
 */
#ifndef HELPDIALOG_H
#define HELPDIALOG_H

#include <QDialog>

namespace Ui {
class HelpDialog;
}

class HelpDialog : public QDialog
{
    Q_OBJECT

public:
    /**
     * Constructor for the help dialog
     * @param parent - The QObject for the help dialog to work with
     */
    explicit HelpDialog(QWidget *parent = nullptr);

    /**
     * Destructor for the help dialog
     */
    ~HelpDialog();

private:
    Ui::HelpDialog *ui;
};

#endif // HELPDIALOG_H

// - Checked by Roland Guerriere
