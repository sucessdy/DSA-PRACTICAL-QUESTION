// Ensure you have the Three.js library loaded in your HTML, as before.

// Global variables (continue from the previous script if possible, or define them)
let scene, camera, renderer, playerToken, board;
// Array to represent the (simplified) path of the board
const boardPath = []; 
const boardSize = 10; // 10x10 board

// --- INITIALIZATION (Extend or replace previous init function) ---
function initGame() {
    // 1. Scene, Camera, Renderer setup (as defined in the coffee example)
    scene = new THREE.Scene();
    camera = new THREE.PerspectiveCamera(75, window.innerWidth / window.innerHeight, 0.1, 1000);
    renderer = new THREE.WebGLRenderer({ antialias: true });
    renderer.setSize(window.innerWidth, window.innerHeight);
    document.body.innerHTML = ''; // Clear previous elements
    document.body.appendChild(renderer.domElement);
    
    // Add lighting (essential for 3D visibility)
    const ambientLight = new THREE.AmbientLight(0x404040, 3); 
    scene.add(ambientLight);
    const dirLight = new THREE.DirectionalLight(0xffffff, 2);
    dirLight.position.set(10, 20, 10);
    scene.add(dirLight);

    // 2. Create the 3D Board (The "Field")
    // A simple plane with an imaginary texture (you'd load a real image)
    const boardGeometry = new THREE.PlaneGeometry(boardSize * 2, boardSize * 2, boardSize, boardSize);
    const boardMaterial = new THREE.MeshLambertMaterial({ 
        color: 0x228B22, // Forest Green
        side: THREE.DoubleSide 
    });
    board = new THREE.Mesh(boardGeometry, boardMaterial);
    board.rotation.x = -Math.PI / 2; // Rotate the plane to be flat on the ground
    scene.add(board);

    // 3. Create the Player Token (A simple cylinder)
    const tokenGeometry = new THREE.CylinderGeometry(0.3, 0.3, 0.5, 32);
    const tokenMaterial = new THREE.MeshPhongMaterial({ color: 0xFF0000 }); // Red token
    playerToken = new THREE.Mesh(tokenGeometry, tokenMaterial);
    
    // Position the token slightly above the board
    playerToken.position.y = 0.25; 
    scene.add(playerToken);

    // 4. Setup Camera Position
    camera.position.set(0, 15, 10); // Look down at the board
    camera.lookAt(0, 0, 0); // Focus on the center of the board

    // 5. Initialize the simplified board path coordinates
    createBoardPath();

    window.addEventListener('resize', onWindowResize, false);
}

// --- GAME LOGIC FUNCTIONS ---

// Function to map game squares (1 to 100) to 3D coordinates
function createBoardPath() {
    // This is a highly simplified coordinate calculation for a 10x10 board centered at (0,0,0)
    // Professional implementation would use a precise array of 100 points.
    const startX = -boardSize + 1;
    const startZ = boardSize - 1; 

    for (let i = 0; i < boardSize * boardSize; i++) {
        const row = Math.floor(i / boardSize);
        const col = i % boardSize;
        
        let x, z;

        if (row % 2 === 0) {
            // Even rows (0, 2, 4...) move left-to-right (0, 1, 2...)
            x = startX + col * 2;
        } else {
            // Odd rows (1, 3, 5...) move right-to-left (9, 8, 7...)
            x = startX + (boardSize - 1 - col) * 2;
        }

        z = startZ - row * 2;

        boardPath.push(new THREE.Vector3(x, 0.25, z));
    }
    
    // Start player at position 0 (the first square)
    playerToken.position.copy(boardPath[0]);
}

// Global state for game
let currentSquare = 0;
const totalSquares = 100;

// Function to simulate a dice roll and move the player token
function movePlayer(steps) {
    let targetSquare = currentSquare + steps;
    if (targetSquare >= totalSquares) {
        targetSquare = totalSquares - 1; // End game/win condition
    }

    // Professional Animation Logic (Using tweening for smooth movement)
    
    // **NOTE: For true professional smooth animation, you would use a dedicated library like TWEEN.js 
    // to smoothly move the token from the old position to the new one over a short time.**
    
    // For now, we instantly snap to the target position:
    const targetPosition = boardPath[targetSquare];
    
    // **TODO:** Implement a TWEEN.js animation here for smooth, step-by-step movement
    
    playerToken.position.copy(targetPosition);
    currentSquare = targetSquare;

    console.log(`Moved ${steps} steps. Current square: ${currentSquare + 1}`);
}


// --- ANIMATION LOOP (The Game Loop) ---
function animateGame() {
    requestAnimationFrame(animateGame);
    
    // Any continuous animation (e.g., subtle board pulse, token idle animation) goes here
    
    renderer.render(scene, camera);
}

// --- HELPER FUNCTION ---
function onWindowResize() {
    camera.aspect = window.innerWidth / window.innerHeight;
    camera.updateProjectionMatrix();
    renderer.setSize(window.innerWidth, window.innerHeight);
}

// --- START THE GAME ---
initGame();
animateGame();

// --- EXAMPLE INTERACTION (How to play) ---
// You can call this in your browser console to test the movement:
// movePlayer(6); 
// movePlayer(3);