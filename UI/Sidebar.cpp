
#include "Sidebar.hpp"


Sidebar::Sidebar() {
    // set the bar to gray color
    bar.setFillColor(Color(200,200,200));
    // sidebar align right
    bar.setPosition(Vector2f(GRAPH_PANEL, 0));
    bar.setSize(Vector2f(SIDE_BAR, WINDOW_HEIGHT));
    
    items.reserve(100);
    
    if (!font.loadFromFile("/Users/winnie/Desktop/GraphingCalculator3.0/Resources/Compagnon-Light.otf")){
        cout<<"Sidebar: Font failed to load. Check absolute path."<<endl;
        cin.get();
        exit(-1);
    }
    
    text.setFont(font);
    text.setCharacterSize(40);
    text.setFillColor(Color::Black);
    text.setStyle(Text::Bold);
    items.push_back("Enter Equation:");
//    items.push_back(" " + _infix_expression);
    //Fill the items vector with empty strings so that we can use [] to read them:
    for (int i=0 ; i < 100; i++){
        items.push_back(" ");
    }
}

void Sidebar::draw(RenderWindow& window) {
    // draw the rectangle side bar box
    window.draw(bar);
    
    // draw the string
    const double VERTICAL_LINE_SPACING = 1.0;
    const double LEFT_MARGIN = GRAPH_PANEL + 10.0;
    
    float height = 2;
    
    
    for (vector<string>::iterator it = items.begin(); it != items.end(); it++) {
        bool blank = false;
        if (strlen(it->c_str()) == 0) {
            //empty rows must be taken into account but not drawn
            blank = true;
            text.setString("BLANK");
        } else {
            cout << it->c_str() << endl;
            text.setString(it->c_str());
        }
        
        text.setPosition(sf::Vector2f(LEFT_MARGIN, height));
        height += text.getLocalBounds().height + VERTICAL_LINE_SPACING;
        
        if (!blank) {
            window.draw(text);
        }
        
    }
    
    
}

string& Sidebar::operator [](int index) {
    return items[index];
}

