const taskList = document.getElementById("task-list");
const newTaskInput = document.getElementById("new-task");
function addTask() {
    const taskText = newTaskInput.value.trim();
    if (taskText === "") return;

    const li = document.createElement("li");
    li.innerHTML = `
        <span>${taskText}</span>
        <button class="delete-btn" onclick="deleteTask(this)">Delete</button>
        <button class="update-btn" onclick="updateTask(this)">Update</button>
    `;

    taskList.appendChild(li);

    newTaskInput.value = "";
}

function deleteTask(button) {
    const li = button.parentElement;
    taskList.removeChild(li);
}


function updateTask(button) {
    const li = button.parentElement;
    const span = li.querySelector("span");

    const newTaskText = prompt("Update task:", span.textContent);
    
    if (newTaskText !== null && newTaskText.trim() !== "") {
        span.textContent = newTaskText;
    }
}