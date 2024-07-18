import React, { useEffect, useRef } from 'react';
import Spotlight from './Spotlight'; // Adjust the import path accordingly
import './Card.css'; // Add your CSS styles

const SectionWithSpotlight: React.FC = () => {
  const containerRef = useRef<HTMLDivElement>(null);

  useEffect(() => {
    if (containerRef.current) {
      new Spotlight(containerRef.current);
    }
  }, []);

  return (
    <div className="section" data-spotlight ref={containerRef}>
      <div className="card">Card 1</div>
      <div className="card">Card 2</div>
      <div className="card">Card 3</div>
    </div>
  );
};

export default SectionWithSpotlight;

import React, { useEffect, useRef } from 'react';
import Spotlight from './Spotlight'; // Adjust the import path accordingly
import './SectionWithSpotlight.css'; // Add your CSS styles

const SectionWithSpotlight: React.FC = () => {
  const containerRef = useRef<HTMLDivElement>(null);

  useEffect(() => {
    if (containerRef.current) {
      new Spotlight(containerRef.current);
    }
  }, []);

  return (
    <div className="section" data-spotlight ref={containerRef}>
      <div className="card">Card 1</div>
      <div className="card">Card 2</div>
      <div className="card">Card 3</div>
    </div>
  );
};

export default SectionWithSpotlight;
