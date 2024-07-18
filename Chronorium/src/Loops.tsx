import Spline from '@splinetool/react-spline';

export default function Loops() {
  return (
    <div className="Secondary-Container">
      <Spline
        scene="https://prod.spline.design/zMCkHBDIpVeWxeED/scene.splinecode"
        style={{ 
          position: 'absolute', 
          top: 0, 
          left: 0, 
          width: '100%', 
          height: '100%', 
          pointerEvents: 'none', 
          backgroundColor: 'transparent' 
        }}
      />
    </div>
  );
}
