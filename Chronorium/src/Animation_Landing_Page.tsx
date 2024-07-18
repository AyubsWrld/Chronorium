import React from 'react';
import Lottie from 'lottie-react';
import animationData from './assets/anims/Landing.json';

const Animation_Landing_Page = () => {
  return (
    <div>
      <Lottie 
        animationData={animationData} 
        loop={false} 
        autoplay={false} 
        style={{ width: 1920 , height: 1080 }} 
      />
    </div>
  );
};

export default Animation_Landing_Page ;
