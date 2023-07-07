import React from 'react';
import { createRoot } from 'react-dom/client';
import Application from './Application';

declare global {
    function GetTabs(): string;
}


const app = <Application />;

// Render application in DOM
createRoot(document.getElementById('app')).render(app);
