#ifndef BUTTONDEMO_H_
#define BUTTONDEMO_H_

#include "wx/wx.h"

/**
 * The main application class.
 */
class ButtonDemo : public wxApp
{
public:
    /**
     * Initialization function that is called when the application opens.
     * @returns true if the app opened successfully, else returns false.
     */
    virtual bool OnInit() override;
};

#endif /* BUTTONDEMO_H_ */
