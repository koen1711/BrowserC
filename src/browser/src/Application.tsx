import React from 'react';
import { ContextProvider, Context } from './Context';
import MainUi from './tabbar/MainUi';

const Application: React.FC = () => {


  return (
    <ContextProvider>
      <MainUi />
    </ContextProvider>
  );
};

export default Application;
