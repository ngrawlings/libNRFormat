//
//  Json.cpp
//  libNrFormat
//
//  Created by Nyhl Rawlings on 17/09/2019.
//  Copyright © 2019 Liquidsoft Studio. All rights reserved.
//

#include "Json.h"
#include <libnrcore/memory/LinkedList.h>

namespace nrcore {
    
    Json::Json(String json) {
        parse(json);
    }
    
    Json::Json(const Json &json) {
        
    }
    
    Json::~Json() {
        
    }
    
    bool Json::parse(String json) {
        LinkedList<char> symbols;
        bool quotation = false;
        bool parsing_value = false;
        int parsing_value_symbol_count = 0;
        
        String name, val;
        
        ssize_t slen = json.length();
        for (int i=0; i<slen; i++) {
            switch (json[i]) {
                case '\\':
                    i++;
                    break;
                    
                case '\"':
                    if (quotation && symbols.length()) {
                        if (!parsing_value && symbols.get(symbols.lastNode()) == '\"') {
                            if (symbols.get(symbols.prevNode(symbols.lastNode())) != '\"') {
                                quotation = false;
                            } else {
                                val += json[i];
                            }
                            symbols.removeNode(symbols.lastNode());
                        } else {
                            val += json[i];
                            if (symbols.get(symbols.lastNode()) == '\"')
                                symbols.removeNode(symbols.lastNode());
                            else
                                symbols.add('\"');
                        }
                    } else {
                        if (!parsing_value)
                            quotation = true;
                        else
                            val += json[i];
                        
                        if (symbols.get(symbols.lastNode()) != '\"')
                            symbols.add('\"');
                        else
                            symbols.removeNode(symbols.lastNode());
                    }
                    break;
                    
                case '[':
                    symbols.add(json[i]);
                    if (parsing_value)
                        val += json[i];
                    break;
                    
                case '{':
                    symbols.add(json[i]);
                    if (parsing_value)
                        val += json[i];
                    break;
                    
                default:
                {
                    switch (json[i]) {
                        case ']':
                            if (symbols.get(symbols.lastNode()) == '[') {
                                symbols.removeNode(symbols.lastNode());
                            }
                            break;
                                
                        case '}':
                            if (symbols.get(symbols.lastNode()) == '{') {
                                symbols.removeNode(symbols.lastNode());
                            }
                            break;
                    }
                    
                    if (!parsing_value && !quotation) {
            
                        if (json[i] == ':' && symbols.length() == 1) {
                            parsing_value = true;
                            parsing_value_symbol_count = symbols.length();
                            name = val;
                            val = "";
                        }
                        
                    } else {
                        if (parsing_value && ((symbols.length() == parsing_value_symbol_count && json[i] == ',') || (!symbols.length() && (json[i] == '}' || json[i] == ']')))) {
                            parsing_value = false;
                            
                            Memory n(name.operator char *(), name.length());
                            values.set(n, val);
                            
                            val = "";
                        } else {
                            val += json[i];
                        }
                    }
                }
                    
            }
        }
        
        return true;
    }
    
    String Json::getString(String name) {
        Memory n(name.operator char *(), name.length());
        return values.get(n);
    }
    
}
