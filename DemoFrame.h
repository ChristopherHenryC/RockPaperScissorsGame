#ifndef DEMOFRAME_H_
#define DEMOFRAME_H_

#include "ButtonPanel.h"

/**
 * The application frame.
 */
class DemoFrame : public wxFrame
{
public:
    /**
     * Constructor.
     * @param title the window title.
     */
    DemoFrame(const wxString& title);

    /**
     * Destructor.
     */
    virtual ~DemoFrame();

    /**
     * Event handler for the About menu item.
     * @param event the item selection event.
     */
    void on_about(wxCommandEvent& event);

    /**
     * Event handler for the Quit menu item.
     * @param event the item selection event.
     */
    void on_quit(wxCommandEvent& event);
    
    //my events
    void on_reset(wxCommandEvent& event);
    void on_query(wxCommandEvent& event);

private:
    // The event table that maps events to their handlers.
    wxDECLARE_EVENT_TABLE();

    void OnReset(wxCommandEvent& event);
    void OnQuery(wxCommandEvent& event);

    ButtonPanel *button_panel;

    /**
     * Initialize the contents of the application frame.
     */
    void init();

    /**
     * Initialize the application frame's menu and status bars.
     */
    void init_menu_bar();

    /**
     * Initialize the application frame's sizer.
     */
    void init_sizer();
};

// IDs for the menu commands.
enum
{
    RPS_Quit  = wxID_EXIT,
    RPS_About = wxID_ABOUT,
    ID_Reset = 1,
    ID_Query = 2
};

#endif /* DEMOFRAME_H_ */
