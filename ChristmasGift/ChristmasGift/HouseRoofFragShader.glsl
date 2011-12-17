#version 130
///////////////////////////////
// fg uniform
///////////////////////////////
uniform sampler2D ColorTexture;

uniform sampler2D permTexture;
uniform sampler1D simplexTexture;
uniform sampler2D gradTexture;
uniform float time; // Used for texture animation

uniform float size;
//texture coord
in vec2 Texcoord;
///////////////////////////////
// fg uniform
///////////////////////////////
out vec4 fragColour;
in vec3 vp;



#define ONE 0.00390625
#define ONEHALF 0.001953125


float fade(float t) {
  return t*t*t*(t*(t*6.0-15.0)+10.0); 
}


float noise(vec2 P)
{
  vec2 Pi = ONE*floor(P)+ONEHALF; 
  vec2 Pf = fract(P);             

  vec2 grad00 = texture2D(permTexture, Pi).rg * 4.0 - 1.0;
  float n00 = dot(grad00, Pf);

  
  vec2 grad10 = texture2D(permTexture, Pi + vec2(ONE, 0.0)).rg * 4.0 - 1.0;
  float n10 = dot(grad10, Pf - vec2(1.0, 0.0));

  
  vec2 grad01 = texture2D(permTexture, Pi + vec2(0.0, ONE)).rg * 4.0 - 1.0;
  float n01 = dot(grad01, Pf - vec2(0.0, 1.0));

  
  vec2 grad11 = texture2D(permTexture, Pi + vec2(ONE, ONE)).rg * 4.0 - 1.0;
  float n11 = dot(grad11, Pf - vec2(1.0, 1.0));

  
  vec2 n_x = mix(vec2(n00, n01), vec2(n10, n11), fade(Pf.x));

  
  float n_xy = mix(n_x.x, n_x.y, fade(Pf.y));

  
  return n_xy;
}


float noise(vec3 P)
{
  vec3 Pi = ONE*floor(P)+ONEHALF; 
                                  
  vec3 Pf = fract(P);     

  
  float perm00 = texture2D(permTexture, Pi.xy).a ;
  vec3  grad000 = texture2D(permTexture, vec2(perm00, Pi.z)).rgb * 4.0 - 1.0;
  float n000 = dot(grad000, Pf);
  vec3  grad001 = texture2D(permTexture, vec2(perm00, Pi.z + ONE)).rgb * 4.0 - 1.0;
  float n001 = dot(grad001, Pf - vec3(0.0, 0.0, 1.0));

  
  float perm01 = texture2D(permTexture, Pi.xy + vec2(0.0, ONE)).a ;
  vec3  grad010 = texture2D(permTexture, vec2(perm01, Pi.z)).rgb * 4.0 - 1.0;
  float n010 = dot(grad010, Pf - vec3(0.0, 1.0, 0.0));
  vec3  grad011 = texture2D(permTexture, vec2(perm01, Pi.z + ONE)).rgb * 4.0 - 1.0;
  float n011 = dot(grad011, Pf - vec3(0.0, 1.0, 1.0));

  
  float perm10 = texture2D(permTexture, Pi.xy + vec2(ONE, 0.0)).a ;
  vec3  grad100 = texture2D(permTexture, vec2(perm10, Pi.z)).rgb * 4.0 - 1.0;
  float n100 = dot(grad100, Pf - vec3(1.0, 0.0, 0.0));
  vec3  grad101 = texture2D(permTexture, vec2(perm10, Pi.z + ONE)).rgb * 4.0 - 1.0;
  float n101 = dot(grad101, Pf - vec3(1.0, 0.0, 1.0));

  
  float perm11 = texture2D(permTexture, Pi.xy + vec2(ONE, ONE)).a ;
  vec3  grad110 = texture2D(permTexture, vec2(perm11, Pi.z)).rgb * 4.0 - 1.0;
  float n110 = dot(grad110, Pf - vec3(1.0, 1.0, 0.0));
  vec3  grad111 = texture2D(permTexture, vec2(perm11, Pi.z + ONE)).rgb * 4.0 - 1.0;
  float n111 = dot(grad111, Pf - vec3(1.0, 1.0, 1.0));

  
  vec4 n_x = mix(vec4(n000, n001, n010, n011),
                 vec4(n100, n101, n110, n111), fade(Pf.x));

  
  vec2 n_xy = mix(n_x.xy, n_x.zw, fade(Pf.y));

  
  float n_xyz = mix(n_xy.x, n_xy.y, fade(Pf.z));

  
  return n_xyz;
}





void main(void)
{
   
  
   
   
   
   float n = 0;//noise(Texcoord * size ) + noise(Texcoord * size/2 )+ noise(Texcoord * size/3 );
   
   for(int i=0;i<5;i++){
      float k = n + noise(Texcoord * size/(i+1) );
      n = k;
   }
  
   
   vec4 c = vec4(1,1,1,1) * vec4(0.5 + 0.5 * vec3(n, n, n), 1.0);
   
   ////////////////////////////////////////////////////////////////
   /**
   float b = 0;   
   for(int i=0;i<5;i++){
      float k = n + noise(Texcoord * size/(i+1)/2 );
      b = k;
   }
   vec4 c1 = vec4(1,1,1,1) * vec4(0.5 + 0.5 * vec3(b, b, b), 1.0);
   c = c + c1;
   */
   /////////////////////////////////////////////////////////////////

   vec4 baseColor = texture2D( ColorTexture, Texcoord.st * 5 );
   
   
   
   if(baseColor.a < 0.15)
      discard;
      else{
      if(size>50)
      fragColour = baseColor;
      else
      fragColour = c +  baseColor;
      if(size < 1.9)
      fragColour = vec4(1,1,1,1);
      
      }
   
   
}