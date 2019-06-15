#include "ButtonPanel.h"
#include <ctime>
#include <cstdlib>
#include <sstream>
#include <string>
#include <iostream>

using namespace std;

void ButtonPanel::init()
{

    srand(time(NULL)); //seeding the rng
    choiceHolder = 0;  //0 = null, 1 = rock, 2 = paper, 3 = scissors
    totalRounds = 20;
    winCount = 0;
    lossCount = 0;
    tieCount = 0;

    wxSizer *sizer = new wxBoxSizer(wxVERTICAL);

    wxPanel *button_panel = new wxPanel(this, wxID_ANY);
    wxSizer *button_sizer = new wxBoxSizer(wxHORIZONTAL);

    wxStaticText *choose_text = new wxStaticText(button_panel, wxID_ANY,
                                                 "Choose:");
    wxButton *rock_button     = new wxButton(button_panel, wxID_ANY,
                                             choice_to_wxString(ROCK));
    wxButton *paper_button    = new wxButton(button_panel, wxID_ANY,
                                             choice_to_wxString(PAPER));
    wxButton *scissors_button = new wxButton(button_panel, wxID_ANY,
                                             choice_to_wxString(SCISSORS));

    rock_button->Bind    (wxEVT_BUTTON, &ButtonPanel::on_rock, this);
    paper_button->Bind   (wxEVT_BUTTON, &ButtonPanel::on_paper, this);
    scissors_button->Bind(wxEVT_BUTTON, &ButtonPanel::on_scissors, this);

    button_sizer->Add(choose_text, 0, 0, 0);
    button_sizer->AddSpacer(5);
    button_sizer->Add(rock_button, 0, 0, 0);
    button_sizer->AddSpacer(5);
    button_sizer->Add(paper_button, 0, 0, 0);
    button_sizer->AddSpacer(5);
    button_sizer->Add(scissors_button, 0, 0, 0);
    button_panel->SetSizer(button_sizer);

    wxPanel *chosen_panel = new wxPanel(this, wxID_ANY);
    wxSizer *chosen_sizer = new wxGridSizer(2, 0, 5);

    wxStaticText *chosen_text = new wxStaticText(chosen_panel, wxID_ANY,
                                                 "Chosen object:");
    button_chosen_text = new wxStaticText(chosen_panel, wxID_ANY, "");
    button_chosen_text->SetFont(button_chosen_text->GetFont().Larger());
    
    chosen_sizer->Add(chosen_text, 0, wxALIGN_RIGHT, 0);
    chosen_sizer->Add(button_chosen_text, 0, 0, 0);
    chosen_panel->SetSizer(chosen_sizer);

     //****** my cool computer code ***************
    wxPanel *computer_panel = new wxPanel(this, wxID_ANY);
    wxSizer *computer_sizer = new wxGridSizer(2, 0, 5);    
    computer_chosen_text = new wxStaticText(computer_panel, wxID_ANY, "");
    computer_chosen_text->SetFont(computer_chosen_text->GetFont().Larger());
    wxStaticText *computer_text = new wxStaticText(computer_panel, wxID_ANY,
                                                 "Computer's choice:");

    computer_sizer->Add(computer_text, 0, wxALIGN_RIGHT, 0);
    computer_sizer->Add(computer_chosen_text, 0, 0, 0);
    computer_panel->SetSizer(computer_sizer);

   //******** my cool score counter code ************
    wxPanel *outcome_panel = new wxPanel(this, wxID_ANY);
    wxSizer *outcome_sizer = new wxGridSizer(2, 0, 5);    
    outcome_text = new wxStaticText(outcome_panel, wxID_ANY, "");
    outcome_text->SetFont(outcome_text->GetFont().Larger());
    wxStaticText *outcome_basic_text = new wxStaticText(outcome_panel, wxID_ANY,
                                                 "Outcome:");
    outcome_sizer->Add(outcome_basic_text, 0, wxALIGN_RIGHT, 0);
    outcome_sizer->Add(outcome_text, 0, 0, 0);
    outcome_panel->SetSizer(outcome_sizer);
    //*************************************
    //***** keep track of wins/losses *****************
    wxPanel *tracker_panel = new wxPanel(this, wxID_ANY);
    wxSizer *tracker_sizer = new wxGridSizer(2, 0, 5);    
    tracker_text = new wxStaticText(tracker_panel, wxID_ANY, "");
    tracker_text->SetFont(tracker_text->GetFont().Larger());
    wxStaticText *tracker_basic_text = new wxStaticText(tracker_panel, wxID_ANY,
                                                 "Wins/Losses/Ties:");
    tracker_sizer->Add(tracker_basic_text, 0, wxALIGN_RIGHT, 0);
    tracker_sizer->Add(tracker_text, 0, 0, 0);
    tracker_panel->SetSizer(tracker_sizer);
    //****************rounds******************
    wxPanel *round_panel = new wxPanel(this, wxID_ANY);
    wxSizer *round_sizer = new wxGridSizer(2, 0, 5);    
    round_text = new wxStaticText(round_panel, wxID_ANY, "");
    //round_text->SetFont(round_text->GetFont().Larger());
    wxStaticText *round_basic_text = new wxStaticText(round_panel, wxID_ANY,
                                                 "Round:");
    round_sizer->Add(round_basic_text, 0, wxALIGN_RIGHT, 0);
    round_sizer->Add(round_text, 0, 0, 0);
    round_panel->SetSizer(round_sizer);

    
    sizer->Add(button_panel, 0, wxALIGN_CENTER, 0);
    sizer->AddSpacer(20);
    sizer->Add(chosen_panel, 0, wxALIGN_CENTER, 0);
    sizer->AddSpacer(20);
    sizer->Add(computer_panel, 0, wxALIGN_CENTER, 0);
    sizer->AddSpacer(20);
    sizer->Add(outcome_panel, 0, wxALIGN_CENTER, 0);
    sizer->AddSpacer(20);
    sizer->Add(tracker_panel, 0, wxALIGN_CENTER, 0);
    sizer->AddSpacer(20);
    sizer->Add(round_panel, 0, wxALIGN_CENTER, 0);
    sizer->AddSpacer(20);

    SetSizer(sizer);
}

void ButtonPanel::on_rock(wxCommandEvent& event)
{
    update_button_choice_text(ROCK);
    choiceHolder = 1;
    update_computer_choice();
}

void ButtonPanel::on_paper(wxCommandEvent& event)
{
    update_button_choice_text(PAPER);
    choiceHolder = 2;
    update_computer_choice();
}

void ButtonPanel::on_scissors(wxCommandEvent& event)
{
    update_button_choice_text(SCISSORS);
    choiceHolder = 3;
    update_computer_choice();
}

void ButtonPanel::update_button_choice_text(const Choice choice)
{
    button_chosen_text->SetLabelText(choice_to_wxString(choice));
}

void ButtonPanel::update_computer_choice()
{
    int randum =  1+ rand() % 3;
    Choice randChoice;
    if(randum > 2)
    {
    	randChoice = ROCK;
	if(choiceHolder == 1){
		outcome_text->SetLabelText("Tie");
		tieCount++;
	}
	else if(choiceHolder == 2){
		outcome_text->SetLabelText("Win");
		winCount++;
	}
	else{
		outcome_text->SetLabelText("Loss");
		lossCount++;
	}
     }
    else if(randum > 1)
    {
	randChoice = PAPER;
	if(choiceHolder == 2){
		outcome_text->SetLabelText("Tie");
		tieCount++;
	}
	else if(choiceHolder == 3){
		outcome_text->SetLabelText("Win");
		winCount++;
	}
	else{
		outcome_text->SetLabelText("Loss");
		lossCount++;
	}
    }
    else
    {
	randChoice = SCISSORS;
	if(choiceHolder == 3){
		outcome_text->SetLabelText("Tie");
		tieCount++;
	}
	else if(choiceHolder == 1){
		outcome_text->SetLabelText("Win");
		winCount++;
	}
	else{
		outcome_text->SetLabelText("Loss");
		lossCount++;
	}
    }

    if(winCount + lossCount + tieCount > totalRounds)
	reset();
    ostringstream str1;
    str1 << winCount << " : " << lossCount << " : " << tieCount ;
    string geek = str1.str();
    tracker_text->SetLabelText(geek);	
    computer_chosen_text->SetLabelText(choice_to_wxString(randChoice));

    ostringstream str2;
    str2 << winCount+lossCount+tieCount << " / " << totalRounds ;
    string geek2 = str2.str();
    round_text->SetLabelText(geek2);

}

void ButtonPanel::setRounds(long i)
{
	totalRounds = i;
	reset();
}

void ButtonPanel::reset()
{
	winCount = 0;
	lossCount = 0;
	tieCount = 0;
	ostringstream str1;
        str1 << winCount+lossCount+tieCount << " / " << totalRounds ;
        string geek = str1.str();
	tracker_text->SetLabelText("0 : 0 : 0");
	round_text->SetLabelText(geek);
	
}
