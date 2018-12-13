
#include "Sidebar.hpp"


Sidebar::Sidebar() {
    // set the bar to beige color
    bar.setFillColor(Color(200,200,200));
    // sidebar align right
    bar.setPosition(Vector2f(GRAPH_PANEL, 0));
    bar.setSize(Vector2f(SIDE_BAR, WINDOW_HEIGHT));
    
//    icons.reserve(100);
    
    if (!font.loadFromFile("/Users/winnie/Desktop/GraphingCalculator3.0/Resources/Compagnon-Light.otf")){
        cout<<"Sidebar: Font failed to load. Check absolute path."<<endl;
        cin.get();
        exit(-1);
    }
    
    expression_text.setFont(font);
    expression_text.setCharacterSize(35);
    expression_text.setFillColor(Color::Black);
    expression_text.setStyle(Text::Bold);
    
    symbol_icon.setFont(font);
    symbol_icon.setCharacterSize(35);
    symbol_icon.setFillColor(Color::Black);
    symbol_icon.setStyle(Text::Bold);
//    //Fill the items vector with empty strings so that we can use [] to read them:
    for (int i = 0 ; i < 100; i++) {
        icons.push_back("boop");
    }
}

void Sidebar::draw(RenderWindow& window) {
    // draw the rectangle side bar box
    window.draw(bar);
    
    // draw the string
    const double VERTICAL_LINE_SPACING = 0.5;
    const double LEFT_MARGIN = GRAPH_PANEL + 10.0; //1350
    const double HORIZONTAL_LINE_SPACING = 0.5;
    
    float height = 50;
    float width = 20;
    float align = LEFT_MARGIN;
    
    expression_text.setPosition(Vector2f(LEFT_MARGIN, height));
    height += expression_text.getLocalBounds().height + VERTICAL_LINE_SPACING;
    window.draw(expression_text);
    
    store_symbol_icons();
    
    int index = 0;
    
//    if (icons[index]  == "boop") {
//        cout << "hey!" << endl;
//    } else {
//        cout << "noo!" << endl;
//    }
    
    while (icons[index] != "boop") {
        
        symbol_icon.setString(icons[index]);
        
        if (index % 3 == 0) {
            symbol_icon.setPosition(Vector2f(align, height));
        } else {
            symbol_icon.setPosition(Vector2f(width, height));
        }
        
        width += width;
        
        
        window.draw(symbol_icon);
        index++;
    }
    
}

string& Sidebar::operator [](int index) {
    return icons[index];
}

void Sidebar::set_infix_expression(string infix_expression) {
    // draw the infix_expression
    expression_text.setString("Entered Expression: " + infix_expression);
}

void Sidebar::store_symbol_icons() {
    
    icons[0] = "1";
    icons[1] = "2";
    icons[2] = "3";
    
}
