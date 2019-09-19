//
//  JsonString.cpp
//  libNrFormat
//
//  Created by Nyhl Rawlings on 19/09/2019.
//  Copyright © 2019 Liquidsoft Studio. All rights reserved.
//

#include "JsonString.h"

namespace nrcore {
    
    JsonString::JsonString(String json) {
        this->value = json.trim(" \"");
    }
    
    JsonString::JsonString(const JsonString &json) {
        this->value = json.value;
    }
    
    JsonString::~JsonString() {
        
    }
    
    JsonString::TYPE JsonString::getType() {
        return STRING;
    }
    
    String JsonString::toString() {
        return String("\"%\"").arg(value);
    }
    
    String JsonString::getValue() {
        return value;
    }
    
}
