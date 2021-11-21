void drawHeader(void) {

TLatex *prelim = new TLatex;
prelim->SetNDC();
prelim->SetTextSize(0.045);
prelim->DrawLatex(0.15, 0.92, "CMS #it{#bf{Internal}}");
prelim->Draw();

TLatex *lumi = new TLatex;
lumi->SetNDC();
lumi->SetTextSize(0.045);
lumi->DrawLatex(0.7, 0.92, "#bf{13 TeV (2018)}");
lumi->Draw();

}


void drawJets(void) {

TLatex *prelim = new TLatex;
prelim->SetNDC();
prelim->SetTextSize(0.035);
prelim->DrawLatex(0.65, 0.75, "#bf{p_{T}^{jet1} > 550 GeV}");
prelim->DrawLatex(0.65, 0.7, "#bf{p_{T}^{jet2} > 500 GeV}");
//prelim->DrawLatex(0.175, 0.35, "#bf{p_{T}^{j1,j2} > 40 GeV}");
prelim->DrawLatex(0.65, 0.65, "#bf{|y_{jet1}|, |y_{jet2}| < 2}");
prelim->DrawLatex(0.65, 0.85, "#bf{PUPPI AK4 jets}");
prelim->Draw();
}

void setTDRStyle() {
  TStyle *tdrStyle = new TStyle("tdrStyle","Style for P-TDR");

// For the canvas:
  tdrStyle->SetCanvasBorderMode(0);
  tdrStyle->SetCanvasColor(kWhite);
    tdrStyle->SetCanvasDefH(480); //Height of canvas
  //  tdrStyle->SetCanvasDefH(450); //Height of canvas
  tdrStyle->SetCanvasDefW(600); //Width of canvas
  tdrStyle->SetCanvasDefX(0);   //POsition on screen
  tdrStyle->SetCanvasDefY(0);

// For the Pad:
  tdrStyle->SetPadBorderMode(0);
  // tdrStyle->SetPadBorderSize(Width_t size = 1);
  tdrStyle->SetPadColor(kWhite);
  tdrStyle->SetPadGridX(false);
  tdrStyle->SetPadGridY(false);
  tdrStyle->SetGridColor(0);
  tdrStyle->SetGridStyle(3);
  tdrStyle->SetGridWidth(1);

// For the frame:
  tdrStyle->SetFrameBorderMode(0);
  tdrStyle->SetFrameBorderSize(1);
  tdrStyle->SetFrameFillColor(0);
  tdrStyle->SetFrameFillStyle(0);
  tdrStyle->SetFrameLineColor(1);
  tdrStyle->SetFrameLineStyle(1);
  tdrStyle->SetFrameLineWidth(1);

// For the histo:
  // tdrStyle->SetHistFillColor(1);
  // tdrStyle->SetHistFillStyle(0);
  tdrStyle->SetHistLineColor(1);
  tdrStyle->SetHistLineStyle(0);
  tdrStyle->SetHistLineWidth(1);
  // tdrStyle->SetLegoInnerR(Float_t rad = 0.5);
  // tdrStyle->SetNumberContours(Int_t number = 20);

  tdrStyle->SetEndErrorSize(2);
  //  tdrStyle->SetErrorMarker(20);
  //  tdrStyle->SetErrorX(0.);
  
  tdrStyle->SetMarkerStyle(20);

//For the fit/function:
  tdrStyle->SetOptFit(1);
  tdrStyle->SetFitFormat("5.4g");
  tdrStyle->SetFuncColor(2);
  tdrStyle->SetFuncStyle(1);
  tdrStyle->SetFuncWidth(1);

//For the date:
  tdrStyle->SetOptDate(0);
  // tdrStyle->SetDateX(Float_t x = 0.01);
  // tdrStyle->SetDateY(Float_t y = 0.01);

// For the statistics box:
  tdrStyle->SetOptFile(0);
  tdrStyle->SetOptStat(0); // To display the mean and RMS:   SetOptStat("mr");
  tdrStyle->SetStatColor(kWhite);
  tdrStyle->SetStatFont(42);
  tdrStyle->SetStatFontSize(0.025);
  tdrStyle->SetStatTextColor(1);
  tdrStyle->SetStatFormat("6.4g");
  tdrStyle->SetStatBorderSize(1);
  tdrStyle->SetStatH(0.1);
  tdrStyle->SetStatW(0.15);
  // tdrStyle->SetStatStyle(Style_t style = 1001);
  // tdrStyle->SetStatX(Float_t x = 0);
  // tdrStyle->SetStatY(Float_t y = 0);

// Margins:
  tdrStyle->SetPadTopMargin(0.1);
  tdrStyle->SetPadBottomMargin(0.2);
  tdrStyle->SetPadLeftMargin(0.2);
  tdrStyle->SetPadRightMargin(0.015);

// For the Global title:

  tdrStyle->SetOptTitle(0);
  tdrStyle->SetTitleFont(42);
  tdrStyle->SetTitleColor(1);
  tdrStyle->SetTitleTextColor(1);
  tdrStyle->SetTitleFillColor(10);
  tdrStyle->SetTitleFontSize(0.05);
  // tdrStyle->SetTitleH(0); // Set the height of the title box
  // tdrStyle->SetTitleW(0); // Set the width of the title box
  // tdrStyle->SetTitleX(0); // Set the position of the title box
  // tdrStyle->SetTitleY(0.985); // Set the position of the title box
  // tdrStyle->SetTitleStyle(Style_t style = 1001);
  // tdrStyle->SetTitleBorderSize(2);

// For the axis titles:

  tdrStyle->SetTitleColor(1, "XYZ");
  tdrStyle->SetTitleFont(42, "XYZ");
  tdrStyle->SetTitleSize(0.055, "XYZ");
  // tdrStyle->SetTitleXSize(Float_t size = 0.02); // Another way to set the size?
  //tdrStyle->SetTitleYSize(Float_t size = 0.02);
  tdrStyle->SetTitleXOffset(.70);
  tdrStyle->SetTitleYOffset(.7);
  // tdrStyle->SetTitleOffset(1.1, "Y"); // Another way to set the Offset

// For the axis labels:

  tdrStyle->SetLabelColor(1, "XYZ");
  tdrStyle->SetLabelFont(42, "XYZ");
  tdrStyle->SetLabelOffset(0.007, "XYZ");
  tdrStyle->SetLabelSize(0.04, "XYZ");

// For the axis:

  tdrStyle->SetAxisColor(1, "XYZ");
//  tdrStyle->SetStripDecimals(kTRUE);
  tdrStyle->SetTickLength(0.03, "XYZ");
  tdrStyle->SetNdivisions(512, "XYZ");
  tdrStyle->SetPadTickX(1);  // To get tick marks on the opposite side of the frame
  tdrStyle->SetPadTickY(1);

// Change for log plots:
  tdrStyle->SetOptLogx(0);
  tdrStyle->SetOptLogy(0);
  tdrStyle->SetOptLogz(0);

// Postscript options:
  tdrStyle->SetPaperSize(20.,20.);
  // tdrStyle->SetLineScalePS(Float_t scale = 3);
  // tdrStyle->SetLineStyleString(Int_t i, const char* text);
  // tdrStyle->SetHeaderPS(const char* header);
  // tdrStyle->SetTitlePS(const char* pstitle);

  // tdrStyle->SetBarOffset(Float_t baroff = 0.5);
  // tdrStyle->SetBarWidth(Float_t barwidth = 0.5);
  // tdrStyle->SetPaintTextFormat(const char* format = "g");
  // tdrStyle->SetPalette(Int_t ncolors = 0, Int_t* colors = 0);
  // tdrStyle->SetTimeOffset(Double_t toffset);
  // tdrStyle->SetHistMinimumZero(kTRUE);

  tdrStyle->cd();
 cout << endl << "    using TDR format: gROOT->SetStyle(\"tdrStyle\");" << endl;
  gROOT->SetStyle("tdrStyle");

}


void DeltaJet2Rapidity_2018()
{

   setTDRStyle();
//   gStyle->SetErrorX(0.);
   TCanvas *c1 = new TCanvas("c1","gerrors2",200,10,1200,1200);

TFile *f2 = new TFile("output_mc_ak418hw.root");
TFile *f3 = new TFile("output_mc_ak418py.root");
TFile *f4 = new TFile("output_mc_ak418mg.root");

TH1F *h2=(TH1F*)f2->Get("DeltaJet2Rapidity");
TH1F *h3=(TH1F*)f3->Get("DeltaJet2Rapidity");
TH1F *h4=(TH1F*)f4->Get("DeltaJet2Rapidity");


//   h->Rebin(3); h2->Rebin(3); h3->Rebin(3); h4->Rebin(3); h5->Rebin(3); h6->Rebin(3); h7->Rebin(3);
   h2->Scale(1/h2->Integral());
   h3->Scale(1./h3->Integral());
   h4->Scale(1./h4->Integral());


   h2->SetMarkerColor(kRed-3);
   h2->SetLineColor(kRed-3);
   h2->SetLineWidth(2);
   h2->SetMarkerStyle(21);
   h2->SetMarkerSize(2);

   h3->SetMarkerColor(kGreen+1);
   h3->SetLineColor(kGreen+1);
   h3->SetLineWidth(2);
   h3->SetMarkerStyle(22);
   h3->SetMarkerSize(2);

   h4->SetMarkerColor(kMagenta+1);
   h4->SetLineColor(kMagenta+1);
   h4->SetLineWidth(2);
   h4->SetMarkerStyle(23);
   h4->SetMarkerSize(2);

/*   h5->SetMarkerColor(kBlack);
   h5->SetLineColor(kBlack);
   h5->SetLineWidth(1);
   h5->SetMarkerStyle(24);
   h5->SetMarkerSize(2);

   h6->SetMarkerColor(kBlue-4);
   h6->SetLineColor(kBlue-4);
   h6->SetLineWidth(1);
   h6->SetMarkerStyle(25);
   h6->SetMarkerSize(2);

   h7->SetMarkerColor(kViolet-1);
   h7->SetLineColor(kViolet-1);
   h7->SetLineWidth(1);
   h7->SetMarkerStyle(26);
   h7->SetMarkerSize(2);
*/
//   h->GetXaxis()->SetRangeUser(0.0, 4.);

   h2->Draw("hist same");
   h3->Draw("hist same");
   h4->Draw("hist same");
 //  h5->Draw("pe hist same");
//   h6->Draw("pe hist same");
//   h7->Draw("pe hist same");


   h2->GetYaxis()->SetTitle("normalized to integral");
   h2->GetYaxis()->CenterTitle();
   h2->GetYaxis()->SetTitleFont(42);
   h2->GetYaxis()->SetTitleSize(0.075);
   h2->GetYaxis()->SetLabelSize(0.035);
   h2->GetYaxis()->SetLabelFont(42);

   h2->GetXaxis()->SetTitle("y^{jet2,gen} - y^{jet2,det}");
   h2->GetXaxis()->CenterTitle();
   h2->GetXaxis()->SetTitleFont(42);
   h2->GetXaxis()->SetTitleSize(0.075);
   h2->GetXaxis()->SetLabelFont(42);
   h2->GetXaxis()->SetLabelSize(0.035);
   drawJets();
   drawHeader();

   auto legend = new TLegend(0.7,0.65,0.9,0.35);
   legend->SetBorderSize(0);
   legend->SetFillStyle(0);
   legend->SetTextSize(0.025);
   legend->AddEntry(h2,"#bf{Herwig++}","l");
   legend->AddEntry(h3,"#bf{Pythia8}","l");
   legend->AddEntry(h4,"#bf{MadGraph+Pythia8}","l");
//   legend->AddEntry(h7,"120 < p_{T}^{j2} < 300 GeV","p");
//   legend->AddEntry(h7,"","p");
   legend->Draw();


//   c1->Draw("same");
   c1->SaveAs("DeltaJet2Rapidity_2018.png");

}
