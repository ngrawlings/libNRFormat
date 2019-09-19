//
//  JsonInvalid.cpp
//  libNrFormat
//
//  Created by Nyhl Rawlings on 19/09/2019.
//  Copyright © 2019 Liquidsoft Studio. All rights reserved.
//

#include "JsonInvalid.h"

namespace nrcore {
    
    JsonInvalid::JsonInvalid(String json) {
        this->json = json;
    }
    
    JsonInvalid::JsonInvalid(const JsonInvalid &json) {
        this->json = json.json;
    }
    
    JsonInvalid::~JsonInvalid() {
        
    }
    
    JsonInvalid::TYPE JsonInvalid::getType() {
        return INVALID;
    }
    
    String JsonInvalid::toString() {
        return json;
    }
    
}
