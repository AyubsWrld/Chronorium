// src/Loops.js

import React from 'react';
import Spline from '@splinetool/react-spline';

export default function Loops() {
  return (
    <div style={{ width: '100%', height: '100%', pointerEvents: 'none'  }}>
      <Spline
        scene="https://prod.spline.design/ia-WeoYgcSe1APyO/scene.splinecode"
        style={{ width: '100%', height: '100%', backgroundColor: 'transparent'  }}
      />
    </div>
  );
}
