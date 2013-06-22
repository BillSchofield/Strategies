//
//  Shader.fsh
//  Strategies
//
//  Created by bschofil on 6/22/13.
//  Copyright (c) 2013 bschofil. All rights reserved.
//

varying lowp vec4 colorVarying;

void main()
{
    gl_FragColor = colorVarying;
}
