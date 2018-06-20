#include "SceneObject.h"
#include "SpriteObject.h"
#include <assert.h>
using std::find;

SceneObject::SceneObject()
{
	
}

SceneObject::~SceneObject()
{
	//detach from the parent node
	//if parent has a child
	if (m_parent != nullptr)
	{
		//remove this child completely
		m_parent->RemoveChild(this);
	}

	//remove all children nodes
	for (auto child : m_children)
	{
		child->m_parent = nullptr;
	}
}

//adds a child to the collection
void SceneObject::AddChild(SceneObject * child)
{
	//make sure it doesnt have a parent already
	assert(child->m_parent == nullptr);
	//assign 'this' as parent
	child->m_parent = this;
	//add new child to the collection
	m_children.push_back(child);
}

//removes the child from the collection
void SceneObject::RemoveChild(SceneObject * child)
{
	//find the child in the collection
	auto iterate = find(m_children.begin(), m_children.end(), child);

	//if found, remove the child
	if (iterate != m_children.end())
	{
		m_children.erase(iterate);
		//then unassign the parent
		child->m_parent = nullptr;
	}
}

void SceneObject::Update(float deltaTime)
{
	//runs 'OnUpdate' function
	OnUpdate(deltaTime);
	//updates the children every frame
	for (auto child : m_children)
	{
		child->Update(deltaTime);
	}
}

void SceneObject::Draw(aie::Renderer2D * renderer)
{
	//run 'OnDraw' function
	OnDraw(renderer);
	//draw the children
	for (auto child : m_children)
	{
		//renderers the children 
		child->Draw(renderer);
	}
}

void SceneObject::UpdateTransform()
{
	//if the parent is not nullptr
	if (m_parent != nullptr)
	{
		m_globalTransform = m_parent->m_globalTransform * m_localTransform;
	}
	else
	{
		m_globalTransform = m_localTransform;
	}

	for (auto child : m_children)
	{
		child->UpdateTransform();
	}
}

//SetPosition: sets the position of the object
void SceneObject::SetPosition(float x, float y)
{
	m_localTransform[2] = { x, y, 1 };
	UpdateTransform();
}

//SetRotate: sets the rotation of the object 
void SceneObject::SetRotate(float radians)
{
	m_localTransform.setRotateZ(radians);
	UpdateTransform();
}

//SetScale: sets the width and height of the object
void SceneObject::SetScale (float width, float height) 
{
	m_localTransform.setScaled(Vector3(width, height, 1));
	UpdateTransform();
}

//Translate: Translates the x and y to constant values 
void SceneObject::Translate(float x, float y)
{
	m_localTransform.translate(x, y);
	//once it updates the x and y values are constants
	UpdateTransform();
}

//Rotate: rotates the z axis of the object
void SceneObject::Rotate(float radians)
{
	m_localTransform.rotateZ(radians);
	UpdateTransform();
}

//Scale: scales the width and height of the object
void SceneObject::Scale(float width, float height)
{
	m_localTransform.scale(Vector3(width, height, 1));
	UpdateTransform();
}

void SceneObject::SetLocal(Matrix3 transform)
{
	m_localTransform = transform;
	UpdateTransform();
}

Matrix3 & SceneObject::GetLocalTransform() 
{
	return m_localTransform;
}

Matrix3 & SceneObject::GetGlobalTransform()
{
	return m_globalTransform;
}
